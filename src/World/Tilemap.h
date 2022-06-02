#pragma once
#include <World/Tile.h>
#include <Assets/Definitions.h>
#include <SFML/Graphics.hpp>
#include <string>
#include <Assets/Definitions.h>

class Tilemap {
/// <summary>
/// Tilemap has an array of tiles 
/// </summary>
private:
	std::string label;
	Tile tilemap[columns][lines];
	sf::Vector2i selectedTileCoords; // coordinates of the current selected tile (ORTHOGONAL)
	TileVariant availableVariant;
public:
	Tilemap();
	std::string getLabel() const { return label; }
	void setLabel(std::string const& lbl) { label = lbl; }
	int setTile(int x, int y, int isoX, int isoY, std::string type, GameAssets const& ga);
	void selectTile(sf::RenderWindow& window, GameAssets const& ga);
	Tile& getTile(sf::Vector2i coords) { return tilemap[coords.y][coords.x]; }
	Tile* getTileRef(sf::Vector2i coords) { return &tilemap[coords.y][coords.x]; }
	int buildTilemap(char fileName[], GameAssets const& ga);
	int draw(sf::RenderWindow &window);
	sf::Vector2i getSelectedTileCoords() { return selectedTileCoords;	}
	// takes in isometric coordinates and returns the tile closest to that point in world space
	Tile& findNearestTileISO(int isoX, int isoY);
	Tile* getPlayerTile();
	int unselectTiles(GameAssets const& ga);
	void removePlayerTile();
	void setAvailableVariant(TileVariant variant); //method that sets up the current variant
};