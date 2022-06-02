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
	sf::Vector2i orthoCoords;
	sf::Vector2f isoCoords;
protected:
	ActorType actorType;
	HealthModule health;
public:
	Actor(std::string texturePath);
	sf::Vector2i getCoordinates() const { return orthoCoords; }
	void setOrthoCoordinates(sf::Vector2i coords) { orthoCoords = coords; }
	sf::Vector2f getIsometricCoordinates() const { return isoCoords; }
	void setIsoCoordinates(sf::Vector2f coords) { isoCoords = coords; }
	sf::Sprite& getSprite() { return actorSprite; }
	virtual int getHealth()	{ return health.getHealth(); }
	virtual void takeDamage(int dmg);
	virtual void death();
	ActorType getType() const { return actorType; };
};