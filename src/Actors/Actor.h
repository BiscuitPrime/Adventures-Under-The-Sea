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
	sf::Vector2i orthoCoords;
	sf::Vector2f isoCoords;
	sf::Sprite actorSprite;
	int id;
protected:
	ActorType actorType;
	HealthModule health;
public:
	Actor(int id, sf::Texture texture);
	sf::Vector2i getCoordinates() const { return orthoCoords; }
	void setOrthoCoordinates(sf::Vector2i coords) { orthoCoords = coords; }
	sf::Vector2f getIsometricCoordinates() const { return isoCoords; }
	void setIsoCoordinates(sf::Vector2f coords) { isoCoords = coords; }
	sf::Sprite& getSprite() { actorSprite.setTexture(actorTexture); return actorSprite; }
	virtual int getHealth()	{ return health.getValue(); }
	virtual void takeDamage(int dmg);
	virtual void death();
	int getId() const { return id; }
	ActorType getType() const { return actorType; };
};