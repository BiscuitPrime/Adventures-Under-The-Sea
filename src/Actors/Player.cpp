/*
* We define the code of the Player class here :
*/
#include "Player.h";

Player::Player(std::string texturePath) : Actor{texturePath}
{
	//playerStates = PlayerStates();
	//_state = STATE_IDLE;
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
