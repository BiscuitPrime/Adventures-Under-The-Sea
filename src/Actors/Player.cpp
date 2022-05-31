#include "Player.h"
#include "Player.h"
#include "Player.h"
/*
* We define the code of the Player class here :
*/
#include "Player.h";
#include <Actors/PlayerCommands/InputHandler.h>

Player::Player(std::string texturePath) : Actor{ texturePath }
{
	health.setInitialHealth(10); //we set up the life at 10 for the player
	oxygen.setInitialOxygen(20); //we set up the player's oxygen at 20 
}

//method that handles the player's death :
void Player::death() 
{
	std::cout << "Player has died\n";
}

//returns the oxygen Module's value
int Player::getOxygen()
{
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