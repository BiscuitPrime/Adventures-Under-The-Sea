#pragma once
#include <Tile.h>
class Tilemap {
private:
	int lines;
	int columns;
	Tile tilemap[][];
public:
	Tilemap(int lines, int columns);
	int getLines() const { return lines; };
	int getColumns() const { return columns; };
	int setTile(Tile tile);
};