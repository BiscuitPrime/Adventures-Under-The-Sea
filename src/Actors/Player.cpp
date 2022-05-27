/*
* We define the code of the Player class here :
*/
#include "Player.h";

Player::Player(std::string texturePath) : Actor{texturePath}
{
	//playerStates = PlayerStates();
}

//method that changes the player's state depending on the input
void Player::handleInput(int input)
{
	if (input == 0)
	{
		//_state = &PlayerStates::idle;
	}
}
