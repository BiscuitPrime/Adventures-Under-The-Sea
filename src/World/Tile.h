#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Tile {
/// <summary>
/// Tile has coordinates that describe its orthogonal position
/// Tile has a string describing its sf::Texture accordingly to the dictionnary in GameAssets.h
/// </summary>
private:
	sf::Vector2i orthogonalCoords;
	sf::Vector2i isometricCoords;
	std::string texture;
public:
	Tile();
	Tile(int x, int y, std::string str);
	void setCoordinates(int x, int y) {
		orthogonalCoords = sf::Vector2i(x, y);
	}
	void setIsometricCoordinates(int x, int y) {
		isometricCoords = sf::Vector2i(x, y);
	}
	std::string getTexture() const { return texture; }
	void setTexture(std::string str) { texture = str; }
	sf::Vector2i getOrthogonalCoords() const { return orthogonalCoords; }
	void draw(sf::RenderWindow& window);
};
