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
	PlayerState* _state; //the pointer that will handle the state of the player
public:
	Player(std::string texturePath);
	void handleInput(int input);
	void update(sf::RenderWindow* window);
	void move(sf::RenderWindow* window);
};