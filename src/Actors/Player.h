#pragma once
#include "Actor.h"
#include <iostream>
#include <SFML/Graphics.hpp>

/*
* Player class
*/

//player class :
class Player : public Actor
{
private:
	OxygenModule oxygen;
public:
	Player(int id, sf::Texture texture);
	void death() override;
	int getOxygen();
	void decreaseOxygen(int value);
	void increaseOxygen(int value);
	void spawnPlayer(sf::Vector2i position);
};