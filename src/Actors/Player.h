#pragma once
#include "Actor.h"
#include <iostream>
#include <Actors/PlayerStates/PlayerStates.h>
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
	Player(std::string texturePath);
	void handleInput(int input);
	void death() override;
	int getOxygen();
	void decreaseOxygen(int value);
	void increaseOxygen(int value);
};