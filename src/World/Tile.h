#pragma once
#include <SFML/Graphics.hpp>

class Tile {
private:
	sf::Vector2f coordinates;
	sf::Sprite sprite;
public:
	sf::Vector2f getCoordinates() const { return coordinates; };
	float getX() const { return coordinates.x; };
	float getY() const { return coordinates.y; };
};