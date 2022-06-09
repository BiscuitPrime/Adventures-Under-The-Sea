#include "Player.h"
#include "Player.h"
/*
* We define the code of the Player class here :
*/
#include <Actors/PlayerCommands/PlayerHandler.h>

Player::Player(int id, sf::Texture texture) : Actor{ id,texture }
{
	oxygen = OxygenModule();
	actorType = PLAYER;
	setOrthoCoordinates(sf::Vector2i(0, 5)); //set orthogonal coordinates
	setIsoCoordinates(Definitions::orthoToIsoWithOffset(sf::Vector2i(0, 5))); //set isometric coordinates
	getSprite().setPosition(getIsometricCoordinates()); //set sprite position
	health.setInitialValue(HEALTH_INITIAL_PLAYER); //we set up the life at 10 for the player
	oxygen.setInitialValue(MAX_OXYGEN); //we set up the player's oxygen at max value
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
	return oxygen.getValue();
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
