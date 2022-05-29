#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Tile {
/// <summary>
/// Tile has coordinates that describe its orthogonal position
/// Tile has a string describing its sf::Texture accordingly to the dictionnary in GameAssets.h
/// </summary>
private:
	int xCoord;
	int yCoord;
	std::string texture;
public:
	Tile();
	Tile(int x, int y, std::string str);
	void setCoordinates(int x, int y) {
		xCoord = x;
		yCoord = y;
	}
	std::string getTexture() const { return texture; }
	void setTexture(std::string str) { texture = str; }
	int getX() const { return xCoord; };
	int getY() const { return yCoord; };
	void draw(sf::RenderWindow &window) const;
};
