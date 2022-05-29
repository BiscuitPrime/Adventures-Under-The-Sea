#pragma once
#include <World/Tile.h>
#include <string>

class Tilemap {
/// <summary>
/// Tilemap has an array of tiles 
/// </summary>
private:
	std::string label;
	int lines = 10;
	int columns = 10;
	Tile tilemap[10][10];
public:
	Tilemap();
	std::string getLabel() const { return label; }
	void setLabel(std::string const& lbl) { label = lbl; }
	int getLines() const { return lines; };
	int getColumns() const { return columns; };
	int setTile(int x, int y, std::string type);
	int buildTilemap(char fileName[]);
	int draw(sf::RenderWindow &window) const;
	std::pair<int, int> static OrthoToIso(std::pair<int, int> coords);
};