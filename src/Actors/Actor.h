#pragma once
#include "SFML/Graphics.hpp"
#include <Actors/Modules/HealthModule.h>
#include <Actors/Modules/OxygenModule.h>

/*
* Actor class, that will define every actor in our system (player and enemy).
*/

enum ActorType {
	PLAYER,
	ENEMY
};

class Actor {
private:
	sf::Texture actorTexture;
	sf::Sprite actorSprite;
	sf::Vector2f actorPosition;
	sf::Vector2i orthoCoords;
	sf::Vector2f isoCoords;
protected:
	ActorType actorType;
	HealthModule health;
public:
	Actor(std::string texturePath);
	sf::Sprite getSprite() { return actorSprite; }
	sf::Vector2f getPosition() { return actorPosition; }
	void setPosition(sf::Vector2f position);
	virtual int getHealth();
	virtual void takeDamage(int dmg);
	virtual void death();
	ActorType getType();
};