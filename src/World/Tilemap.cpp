#include "Tilemap.h"
#include "pugixml.hpp"
#include <iostream>


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

int Tilemap::setTile(int x, int y, std::string type)
{
	// sets ptr to a tile at its corresponding coordinate in the tilemap;
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
	tile.setTexture(type);
	tilemap[y][x] = tile;
	std::cout << "After setting tile: (" << tilemap[y][x].getX() << ", " << tilemap[y][x].getY() << ")\n";
	return 0;
}

int Tilemap::buildTilemap(char fileName[])
{
	std::cout << "Start building\n";
	// build the tilemap array from a xml file (see format in resources/images/tilemap/..)
	pugi::xml_document doc;
	char filePath[400];
	strcpy(filePath, "../../../../resources/images/tilemap/");
	strcat(filePath, fileName);
	pugi::xml_parse_result result = doc.load_file(filePath);
	if (!result)
	{
		std::cerr << "Could not open file because " << result.description() << std::endl;
	}

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
			// set the tile in the tilemap
			std::cout << "Coordinates parsed: (" << xCoord << ", " << yCoord << ")\n";
			std::cout << "Type parsed:" << tileTypeStr << "\n";
			setTile(xCoord, yCoord, tileTypeStr);
		}
	}
	std::cout << "Finish building\n";
	return 0;
}

int Tilemap::draw(sf::RenderWindow &window)
{
	for (int y = 0; y < lines; y++) {
		for (int x = 0; x < columns; x++) {
			Tile tile = tilemap[x][y];
			std::cout << "Before drawing tile : (" << tile.getX() << ", " << tile.getY() << ")\n";
			tile.draw(window);
		}
	}
	return 0;
}


