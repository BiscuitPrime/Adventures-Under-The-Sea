#pragma once
#include <World/Tile.h>
#include <Assets/Definitions.h>
#include <SFML/Graphics.hpp>
#include <string>

class Tilemap {
/// <summary>
/// Tilemap has an array of tiles 
/// </summary>
private:
	std::string label;
	Tile tilemap[columns][lines];
	sf::Vector2i selectedTileCoords;
public:
	Tilemap();
	std::string getLabel() const { return label; }
	void setLabel(std::string const& lbl) { label = lbl; }
	int setTile(int x, int y, int isoX, int isoY, std::string type);
	void selectTile(Tile tile);
	Tile& getTile(int x, int y) { return tilemap[x][y]; }
	int buildTilemap(char fileName[]);
	int draw(sf::RenderWindow &window, GameAssets ga);

	// takes in isometric coordinates and returns the tile closest to that point in world space
	Tile& findNearestTileISO(int isoX, int isoY);

};