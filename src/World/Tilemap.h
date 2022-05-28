#pragma once
#pragma once
#include <World/Tile.h>
#include <string>

class Tilemap {
private:
	int lines = 10;
	int columns = 10;
	Tile tilemap;
public:
	explicit Tilemap(std::string fileName);
	int getLines() const { return lines; };
	int getColumns() const { return columns; };
	int setTile(Tile* tile);
	int buildTilemap(std::string fileName);
};