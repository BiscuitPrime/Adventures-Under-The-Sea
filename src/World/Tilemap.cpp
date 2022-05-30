#include "Tilemap.h"
#include "pugixml.hpp"
#include "Assets/Definitions.h"
#include <iostream>
#include <math.h>


Tilemap::Tilemap()
{
	// initialize tilemap array with basic tiles 
	for (int y = 0; y < lines; y++) {
		for (int x = 0; x < columns; x++) {
			auto tile = Tile();
			tilemap[x][y] = tile;
		}
	}
}

int Tilemap::setTile(int x, int y, int isoX, int isoY, std::string type)
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
	Tile tile = tilemap[y][x];
	tile.setCoordinates(x, y);
	tile.setIsometricCoordinates(isoX, isoY);
	tile.setTexture(type);
	sf::Sprite sprite;
	tile.setSprite(sprite);
	tilemap[y][x] = tile;
	return 0;
}

int Tilemap::buildTilemap(char fileName[])
{
	// build the tilemap array from a xml file (see format in resources/images/tilemap/..)

	// loads xml file
	pugi::xml_document doc;
	char filePath[400];
	strcpy(filePath, "../../../../resources/images/tilemap/");
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
			std::pair<int, int> isoCoords = Definitions::orthoToIso(std::pair<int, int>(xCoord, yCoord));
			std::pair<int, int> offset = { windowWidth / 2, windowHeight / 2 };
			std::pair<int, int> worldCoords{ isoCoords.first + offset.first, isoCoords.second + offset.second };
			// set the tile in the tilemap
			int rt = setTile(xCoord, yCoord, worldCoords.first, worldCoords.second, tileTypeStr);
			// store isometric coordinates
			if (rt < 0) return -1;
		}
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



