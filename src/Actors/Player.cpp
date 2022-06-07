#include "Player.h"
#include "Player.h"
/*
* We define the code of the Player class here :
*/
#include <Actors/PlayerCommands/InputHandler.h>

Player::Player(int id, sf::Texture texture) : Actor{ id,texture }
{
	actorType = PLAYER;
	setOrthoCoordinates(sf::Vector2i(0, 5)); //set orthogonal coordinates
	setIsoCoordinates(Definitions::orthoToIsoWithOffset(sf::Vector2i(0, 5))); //set isometric coordinates
	getSprite().setPosition(getIsometricCoordinates()); //set sprite position
	health.setInitialHealth(10); //we set up the life at 10 for the player
	oxygen.setInitialOxygen(MAX_OXYGEN); //we set up the player's oxygen at 20 
}

//method that handles the player's death :
void Player::death() 
{
	std::cout << "Player has died\n";
	exit(0);
}

//returns the oxygen Module's value
int Player::getOxygen()
{
	if (oxygen.getOxygen() == 0) //if the player's oxygen reaches 0, we call it's death function
	{
		death();
	}
	return oxygen.getOxygen();
}

//decrease's the oxygen's module value
void Player::decreaseOxygen(int value)
{
	oxygen.decreaseOxygen(value);
}

//increase's the oxygen's module value
void Player::increaseOxygen(int value)
{
	oxygen.increaseOxygen(value);
}

//method that spawns the player for a given level
void Player::spawnPlayer(sf::Vector2i position)
{
	setOrthoCoordinates(position); //set orthogonal coordinates
	setIsoCoordinates(Definitions::orthoToIsoWithOffset(position)); //set isometric coordinates
	getSprite().setPosition(getIsometricCoordinates()); //set sprite position
}
