#pragma once

#include <SFML/Graphics.hpp>
#include <Assets/GameAssets.h>

class Entity {
protected:
	sf::Texture entityTexture;
	sf::Sprite entitySprite;
	sf::Vector2i orthoCoords;
	sf::Vector2f isoCoords;
public:
	sf::Vector2i getCoordinates() const { return orthoCoords; }
	void setOrthoCoordinates(sf::Vector2i coords) { orthoCoords = coords; }
	sf::Vector2f getIsometricCoordinates() const { return isoCoords; }
	void setIsoCoordinates(sf::Vector2f coords) { isoCoords = coords; }
	sf::Sprite& getSprite() { return entitySprite; }
};
