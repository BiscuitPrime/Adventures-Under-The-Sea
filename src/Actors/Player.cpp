/*
* We define the code of the Player class here :
*/
#include "Player.h";
#include <Actors/PlayerCommands/InputHandler.h>

Player::Player(std::string texturePath) : Actor{ texturePath }
{
	health.setInitialHealth(10); //we set up the life
}

//method that handles the player's death :
void Player::death() 
{
	std::cout << "Player has died\n";
}