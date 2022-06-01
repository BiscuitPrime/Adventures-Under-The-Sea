#include "Tilemap.h"
#include "pugixml.hpp"
#include <iostream>
#include <math.h>

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
}

int Tilemap::setTile(int x, int y, int isoX, int isoY, std::string type, GameAssets const& ga)
{
	// sets ptr to a tile at its corresponding coordinate in the tilemap
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

void Tilemap::selectTile(sf::RenderWindow &window, GameAssets const& ga)
{
	// convert isometric mouse coordinates to orthogonal normalized ones to get tile position in array
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	sf::Vector2i adjustedWorldPosition = sf::Vector2i((int) (mousePosition.x - (windowWidth / 2) - 32), (int) (mousePosition.y - (windowHeight / 2) - 32));
	sf::Vector2f orthogonalMousePos = Definitions::isoToOrtho(adjustedWorldPosition);
	sf::Vector2i selectedTileOrthoPos = sf::Vector2i(round(orthogonalMousePos.x), round(orthogonalMousePos.y));
	// prevent mouse to generate coordinates out of bounds
	if (orthogonalMousePos.x >= 0 && orthogonalMousePos.x < columns && orthogonalMousePos.y >= 0 && orthogonalMousePos.y < lines) {
		Tile& newlySelectedTile = tilemap[selectedTileOrthoPos.y][selectedTileOrthoPos.x];

		sf::Vector2i newlySelectedTileCoords = newlySelectedTile.getOrthogonalCoords();
		if (selectedTileCoords != newlySelectedTileCoords) {
			Tile& previouslySelectedTile = tilemap[selectedTileCoords.y][selectedTileCoords.x];
			// set the right textures
			int rt = previouslySelectedTile.unloadSelectedTextureVariant(ga);
			if (rt < 0) {
				std::cout << "Error when selecting tile: selected texture could not be unloaded\n";
			}
			rt = newlySelectedTile.loadSelectedTextureVariant(ga);
			if (rt < 0) {
				std::cout << "Error when selecting tile: selected texture could not be loaded\n";
			}
			// store info regarding newly selected tile
			selectedTileCoords = newlySelectedTile.getOrthogonalCoords();
			
			draw(window);
			window.display();
		}
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
	for (auto tileTypeNode : tilemapNode.children("Tiletype")){
		std::string tileTypeStr = tileTypeNode.attribute("type").as_string();
		for (auto tileNode : tileTypeNode.children("Tile")) {
			// retrieve coordinates in xml file
			float xCoord = tileNode.attribute("x").as_float();
			float yCoord = tileNode.attribute("y").as_float();
			if (xCoord < 0 || yCoord < 0 || xCoord >= columns || yCoord >= lines) {
				std::cerr << "Error when parsing xml file: tile coordinates (" << xCoord << ", " << yCoord << ") exceed bounds\n";
				return -1;
			}
			// process isometric coordinates
			// PUT THESE THREE LINES IN DEFINITIONS -------------------------------------------------------------------
			sf::Vector2f isoCoords = Definitions::orthoToIso(sf::Vector2i(xCoord, yCoord));
			sf::Vector2f offset = { windowWidth / 2, windowHeight / 2 };
			sf::Vector2f worldCoords = isoCoords + offset;
			// PUT THESE THREE LINES IN DEFINITIONS -------------------------------------------------------------------

			// set the tile in the tilemap
			int rt = setTile(xCoord, yCoord, worldCoords.x, worldCoords.y, tileTypeStr, ga);
			// store isometric coordinates
			if (rt < 0) return -1;
		}
	}
	return 0;
}

//get the selected Tile coords
sf::Vector2i* Tilemap::getSelectedTileCoords()
{
	return &selectedTileCoords;
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


// outdated
Tile& Tilemap::findNearestTileISO(int isoX, int isoY)
{
	float minDistance = 9999999;
	Tile& nearestTile =  tilemap[0][0];
	for (int y = 0; y < lines; y++) {
		for (int x = 0; x < columns; x++) {
			sf::Vector2i isoTileCoords = tilemap[y][x].getIsometricCoords();
			float newDistance = sqrtf(pow((isoTileCoords.x - isoX), 2) + pow((isoTileCoords.y - isoY), 2));
			if (newDistance < minDistance) {
				minDistance = newDistance;
				nearestTile = tilemap[y][x];
			}
		}
	}
	return nearestTile;
}

