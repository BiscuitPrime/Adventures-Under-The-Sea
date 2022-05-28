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
public:
	Player(std::string texturePath);
	void handleInput(int input);
};