#include "Tilemap.h"
#include "Tilemap.h"
#include "pugixml.hpp"
#include <iostream>
#include <math.h>

Tilemap::Tilemap():
label(""),selectedTileCoords{ sf::Vector2i(0, 0) }
{
	// initialize tilemap array with basic tiles 
	for (int y = 0; y < LINES; y++) {
		for (int x = 0; x < COLUMNS; x++) {
			auto tile = Tile();
			tilemap[y][x] = tile;
		}
	}
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
	sprite.setPosition((float)isoX, (float)isoY);

	std::map<std::string, sf::Texture> tileIndexes = ga.tileIndexes;
	if (!tileIndexes.contains(type)) {
		std::cout << "Error when setting tile: texture \'" << type << "\' could not be found\n"; 
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
void Tilemap::selectTile(sf::RenderWindow &window, GameAssets const& ga)
{
	// convert isometric mouse coordinates to orthogonal normalized ones to get tile position in array
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	auto adjustedWorldPosition = sf::Vector2i((mousePosition.x - (WINDOW_WIDTH / 2) - 32), (mousePosition.y - (WINDOW_HEIGHT / 2) - 32));
	sf::Vector2f orthogonalMousePos = Definitions::isoToOrtho(adjustedWorldPosition);
	auto selectedTileOrthoPos = sf::Vector2i((int)round(orthogonalMousePos.x), (int)round(orthogonalMousePos.y));

	// prevent mouse to generate coordinates out of bounds
	if (orthogonalMousePos.x >= 0 && orthogonalMousePos.x < COLUMNS && orthogonalMousePos.y >= 0 && orthogonalMousePos.y < LINES) {
		Tile& newlySelectedTile = tilemap[selectedTileOrthoPos.y][selectedTileOrthoPos.x];
		sf::Vector2i newlySelectedTileCoords = newlySelectedTile.getOrthogonalCoords();

		//if the selectedTile is new :
		if (selectedTileCoords != newlySelectedTileCoords) {
			Tile& previouslySelectedTile = tilemap[selectedTileCoords.y][selectedTileCoords.x];
			// set the right textures
			if (previouslySelectedTile.getAvailable())
			{
				// in case the tile must be unselected yet remain highlighted we reload the texture variant stored in the tile
				if (previouslySelectedTile.getVariant() == MOVEMENT_SELECTED) {
					previouslySelectedTile.setVariant(MOVEMENT);
				}
				else if (previouslySelectedTile.getVariant() == ATTACK_SELECTED) {
					previouslySelectedTile.setVariant(ATTACK);
				}
				else {
					std::cout << "Error when selecting tiles: previously selected tile has not the variant selected\n";
				}
				previouslySelectedTile.loadTextureVariant(ga);
			} 
			else 
			{
				// unload texture and set it back to base texture
				previouslySelectedTile.unloadTextureVariant(ga);
			}

			// Add 'selected' to the tile variant
			if (TileVariant newlySelectedTileVariant = newlySelectedTile.getVariant(); newlySelectedTileVariant == VANILLA) newlySelectedTile.setVariant(SELECTED);
			else if (newlySelectedTileVariant == MOVEMENT) newlySelectedTile.setVariant(MOVEMENT_SELECTED);
			else if (newlySelectedTileVariant == ATTACK) newlySelectedTile.setVariant(ATTACK_SELECTED);
			// reload the textures
			newlySelectedTile.loadTextureVariant(ga);
			previouslySelectedTile.loadTextureVariant(ga);
			// store info regarding newly selected tile
			selectedTileCoords = newlySelectedTile.getOrthogonalCoords();
			
			draw(window);
			window.display();
		}
	}
}

int Tilemap::setEntity(int x, int y, [[maybe_unused]]int isoX, [[maybe_unused]]int isoY, std::string type, GameAssets const& ga) {
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
		std::cout << "Print Bubble\n";
		auto orthoCoords = sf::Vector2i(x, y);
		// create static bubble --> how to destroy the bubble once used ? 
		sf::Sprite bubbleSprite;
		bubbleSprite.setTexture(ga.Bubble);
		bubbleSprite.setPosition((sf::Vector2f) tile.getIsometricCoords());
		tile.setBubbleSprite(bubbleSprite);
		tile.setBubbleState(true);
	}
	return 0;
}

int Tilemap::buildTilemap(char fileName[], GameAssets const& ga)
{
	// build the tilemap array from a xml file (see format in resources/images/tilemap/..)

	// loads xml file
	pugi::xml_document doc;
	if (pugi::xml_parse_result result = doc.load_file(fileName); !result)
	{
		std::cerr << "Could not open file because " << result.description() << std::endl;
	}

	// parse xml
	auto tilemapNode = doc.child("Tilemap");
	setLabel(tilemapNode.attribute("label").as_string());
	if (tilemapNode.attribute("lines").as_int() != LINES || tilemapNode.attribute("columns").as_int() != COLUMNS) {
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
			int rt = setTile(xCoord, yCoord, (int)worldCoords.x, (int)worldCoords.y, tileTypeStr, accessibility, ga);
			// store isometric coordinates
			if (rt < 0) return -1;
		}
	}
	for (auto entityNode : tilemapNode.children("Entity")) {
		std::string entityType = entityNode.attribute("type").as_string();
		auto xCoord = entityNode.attribute("x").as_int();
		auto yCoord = entityNode.attribute("y").as_int();
		sf::Vector2f worldCoords = Definitions::orthoToIsoWithOffset(sf::Vector2i(xCoord, yCoord));
		setEntity(xCoord, yCoord, (int)worldCoords.x, (int)worldCoords.y, entityType, ga);
	}
	return 0;
}

Tile* Tilemap::getTile(sf::Vector2i coords)
{
	if (Definitions::positionIsWithinTilemapBounds(coords)) {
		return &tilemap[coords.y][coords.x];
	}
	std::cout << "Error when getting tile: out of bounds\n";
	return nullptr;
}

int Tilemap::draw(sf::RenderWindow &window)
{
	// run through the tilemap array and call Tile.draw() for each one
	for (int y = 0; y < LINES; y++) {
		for (int x = 0; x < COLUMNS; x++) {
			Tile& tile = tilemap[x][y];
			tile.draw(window);
		}
	}
	return 0;
}

//function that unloads all the variants
int Tilemap::removeAllTileVariants(GameAssets const& ga) {
	for (int y = 0; y < LINES; y++) {
		for (int x = 0; x < COLUMNS; x++) {
			Tile* tile = &tilemap[y][x];
			if (int unload = tile->unloadTextureVariant(ga); unload == -1)
			{
				std::cout << "Error while unloading the texture\n";
				return -1;
			}
			tile->setAvailable(false);
		}
	}
	return 0;
}

