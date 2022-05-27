#pragma once
#include "SFML/Graphics.hpp"

/*
* Actor class, that will define every actor in our system (player and enemy).
*/
class Actor {
private :
	sf::Texture actorTexture;
	sf::Sprite actorSprite;
	sf::Vector2f actorPosition;
public:
	Actor(std::string texturePath);
	sf::Sprite getSprite();
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f position);
};