/*
* We define the code of the Player class here :
*/
#include "Player.h";

Player::Player(std::string texturePath) : Actor{ texturePath }
{
	_state = &PlayerStates::idle;//by default, player is in it's default (idle) state
}

//method that changes the player's state depending on the input
void Player::handleInput(int input)
{
	//WHAT TO DO NOW :
	/*
	* - Do some ifs etc
	*/
	_state = &PlayerStates::idle;
}
