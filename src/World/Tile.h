#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Tile {
private:
	int xCoord = 666;
	int yCoord = 666;
	std::string texture;
public:
	Tile();
	Tile(int x, int y, std::string str);
	void setCoordinates(int x, int y) {
		std::cout << "trying to set coords from (" << xCoord << ", " << yCoord << ") to (" << x << ", " << y << ")\n";
		xCoord = x;
		yCoord = y;
	}
	std::string getTexture() const { return texture; }
	void setTexture(std::string str) { texture = str; }
	int getX() const { return xCoord; };
	int getY() const { return yCoord; };
	void draw(sf::RenderWindow &window);
};
