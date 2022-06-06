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
public:
	Tilemap();
	std::string getLabel() const { return label; }
	void setLabel(std::string const& lbl) { label = lbl; }
	int setTile(int x, int y, int isoX, int isoY, std::string type, bool accessibility, GameAssets const& ga);
	int setEntity(int x, int y, int isoX, int isoY, std::string type, GameAssets const& ga);
	void selectTile(sf::RenderWindow& window, GameAssets const& ga);
	Tile* getTile(sf::Vector2i coords);
	sf::Vector2i getSelectedTileCoords() { return selectedTileCoords;	}
	int buildTilemap(char fileName[], GameAssets const& ga);
	int draw(sf::RenderWindow &window);
	int removeAllTileVariants(GameAssets const& ga);
};
