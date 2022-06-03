#include "Tilemap.h"
#include "Entities/Entity.h"
#include "pugixml.hpp"
#include <iostream>
#include <math.h>
#include <Entities/Bubble.h>

Tilemap::Tilemap():
label("")
{
	// initialize tilemap array with basic tiles 
	selectedTileCoords = sf::Vector2i(0, 0);
	for (int y = 0; y < lines; y++) {
		for (int x = 0; x < columns; x++) {
			auto tile = Tile();
			tilemap[y][x] = tile;
		}
	}
	availableVariant = MOVEMENT;
}

int Tilemap::setTile(int x, int y, int isoX, int isoY, std::string type, bool accessibility, GameAssets const& ga)
{
	// sets properties of a tile at its corresponding coordinate in the tilemap
	if (x < 0 || x >= 10) {
		std::cout << "Could not set tile: x coordinate out of bounds\n";
		return -1;
	}
	if (y < 0 || y >= 10) {
		std::cout << "Could not set tile: y coordinate out of bounds\n";
		return -1;
	}
	Tile& tile = tilemap[y][x];
	// update tile properties
	tile.setCoordinates(x, y);
	tile.setIsometricCoordinates(isoX, isoY);
	tile.setAccessibility(accessibility);
	// generate sprite for the tile
	sf::Sprite sprite;
	sprite.setPosition(isoX, isoY);

	std::map<std::string, sf::Texture> tileIndexes = ga.tileIndexes;
	if (!tileIndexes.contains(type)) {
		std::cout << "Error when drawing tile: texture \'" << type << "\' could not be found\n"; 
		return -1;
	}
	tile.setStringTexture(type);
	tile.setTexture(tileIndexes.at(type));
	sprite.setTexture(tile.getTexture());
	// load sprite
	tile.setSprite(sprite);
	tilemap[y][x] = tile;
	return 0;
}

//method that selects a tile under the mouse cursor
void Tilemap::selectTile(sf::RenderWindow &window, GameAssets const& ga) //TO REWRITE
{
	// convert isometric mouse coordinates to orthogonal normalized ones to get tile position in array
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	sf::Vector2i adjustedWorldPosition = sf::Vector2i((int) (mousePosition.x - (windowWidth / 2) - 32), (int) (mousePosition.y - (windowHeight / 2) - 32));
	sf::Vector2f orthogonalMousePos = Definitions::isoToOrtho(adjustedWorldPosition);
	sf::Vector2i selectedTileOrthoPos = sf::Vector2i(round(orthogonalMousePos.x), round(orthogonalMousePos.y));
	TileVariant variant = SELECTED;

	// prevent mouse to generate coordinates out of bounds
	if (orthogonalMousePos.x >= 0 && orthogonalMousePos.x < columns && orthogonalMousePos.y >= 0 && orthogonalMousePos.y < lines) {
		Tile& newlySelectedTile = tilemap[selectedTileOrthoPos.y][selectedTileOrthoPos.x];
		sf::Vector2i newlySelectedTileCoords = newlySelectedTile.getOrthogonalCoords();

		//if the selectedTile is new :
		if (selectedTileCoords != newlySelectedTileCoords) {
			Tile& previouslySelectedTile = tilemap[selectedTileCoords.y][selectedTileCoords.x];
			int rt;
			// set the right textures
			if (previouslySelectedTile.getAvailable()) //if the previously selected tile is available, we let it remain available
			{
				if (availableVariant == MOVEMENT) 
				{
					rt = previouslySelectedTile.loadSelectedTextureVariant(ga, MOVEMENT);
				}
				else if (availableVariant == ATTACK)
				{
					rt = previouslySelectedTile.loadSelectedTextureVariant(ga, ATTACK);
				}
				if (rt < 0) {
					std::cout << "Error when selecting tile: selected texture could not be unloaded \n";
				}
			} 
			else 
			{
				rt = previouslySelectedTile.unloadSelectedTextureVariant(ga);
				if (rt < 0) {
					std::cout << "Error when selecting tile: selected texture could not be unloaded (origin:Tilemap.cpp)\n";
				}
			}

			rt = newlySelectedTile.loadSelectedTextureVariant(ga,variant);
			if (rt < 0) {
				std::cout << "Error when selecting tile: selected texture could not be loaded (origin:Tilemap.cpp)\n";
			}
			// store info regarding newly selected tile
			selectedTileCoords = newlySelectedTile.getOrthogonalCoords();
			
			draw(window);
			window.display();
		}
	}
}

int Tilemap::setEntity(int x, int y, int isoX, int isoY, std::string type, GameAssets const& ga) {
	// sets ptr to a tile at its corresponding coordinate in the tilemap
	if (x < 0 || x >= 10) {
		std::cout << "Could not set entity: x coordinate out of bounds\n";
		return -1;
	}
	if (y < 0 || y >= 10) {
		std::cout << "Could not set entity: y coordinate out of bounds\n";
		return -1;
	}
	Tile& tile = tilemap[y][x];

	// initialize the proper entity 
	if (type == "bubble") {
		auto orthoCoords = sf::Vector2i(x, y);
		auto bubble = Bubble(orthoCoords, sf::Vector2f(isoX, isoY), ga);

		tile.setBubbleState(true);
		tile.setBubble(bubble);
	}
}

int Tilemap::buildTilemap(char fileName[], GameAssets const& ga)
{
	// build the tilemap array from a xml file (see format in resources/images/tilemap/..)

	// loads xml file
	pugi::xml_document doc;
	char filePath[400];
	strcpy(filePath, "resources/tilemaps/");
	strcat(filePath, fileName);
	pugi::xml_parse_result result = doc.load_file(filePath);
	if (!result)
	{
		std::cerr << "Could not open file because " << result.description() << std::endl;
	}

	// parse xml
	auto tilemapNode = doc.child("Tilemap");
	setLabel(tilemapNode.attribute("label").as_string());
	if (tilemapNode.attribute("lines").as_int() != lines || tilemapNode.attribute("columns").as_int() != columns) {
		std::cerr << "Error when parsing xml file: line or column not equal to 10\n";
		return -1;
	}
	// parse all <Tiletype type"sand" accessibility="true"> nodes
	for (auto tileTypeNode : tilemapNode.children("Tiletype")){
		std::string tileTypeStr = tileTypeNode.attribute("type").as_string();
		bool accessibility = tileTypeNode.attribute("accessibility").as_bool();
		
		// parse all <Tile x="0" y="0"> nodes
		for (auto tileNode : tileTypeNode.children("Tile")) {
			// retrieve coordinates in xml file
			auto xCoord = tileNode.attribute("x").as_int();
			auto yCoord = tileNode.attribute("y").as_int();
			// process isometric coordinates
			sf::Vector2f worldCoords = Definitions::orthoToIsoWithOffset(sf::Vector2i(xCoord, yCoord));
			// set the tile in the tilemap
			int rt = setTile(xCoord, yCoord, worldCoords.x, worldCoords.y, tileTypeStr, accessibility, ga);
			// store isometric coordinates
			if (rt < 0) return -1;
		}
	}
	for (auto entityNode : tilemapNode.children("Entity")) {
		std::string entityType = entityNode.attribute("type").as_string();
		auto xCoord = entityNode.attribute("x").as_int();
		auto yCoord = entityNode.attribute("y").as_int();
		sf::Vector2f worldCoords = Definitions::orthoToIsoWithOffset(sf::Vector2i(xCoord, yCoord));
		setEntity(xCoord, yCoord, worldCoords.x, worldCoords.y, entityType, ga);
	}
	return 0;
}

int Tilemap::draw(sf::RenderWindow &window)
{
	// run through the tilemap array and call Tile.draw() for each one
	for (int y = 0; y < lines; y++) {
		for (int x = 0; x < columns; x++) {
			Tile& tile = tilemap[x][y];
			tile.draw(window);
		}
	}
	return 0;
}

//function that unloads all the variants
int Tilemap::removeAllTileVariants(GameAssets const& ga) {
	for (int y = 0; y < lines; y++) {
		for (int x = 0; x < columns; x++) {
			Tile* tile = &tilemap[y][x];
			int unload = tile->unloadSelectedTextureVariant(ga);
			if (unload == -1)
			{
				std::cout << "Error while unloading the texture\n";
				return -1;
			}
			tile->setAvailable(false);
		}
	}
}

