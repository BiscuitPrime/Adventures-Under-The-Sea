#pragma once
#include <Actors/Player.h>
#include <Actors/Enemy.h>

class MovementStrategy{
public:
	virtual sf::Vector2i execute(sf::Vector2i enemyPos, sf::Vector2i playerPos, Tilemap* tilemap, int movementRange) {
		return sf::Vector2i(0, 0);
	}
};