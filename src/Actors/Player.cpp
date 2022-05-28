/*
* We define the code of the Player class here :
*/
#include "Player.h";
#include <Actors/PlayerCommands/InputHandler.h>

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

//the player move function, that moves the player :
void Player::move(sf::RenderWindow* window)
{
	sf::Vector2i pixelMousePos = sf::Mouse::getPosition(*window); //get the current mouse position in the window
	sf::Vector2f worldMousePos = window->mapPixelToCoords(pixelMousePos);
	this->setPosition(worldMousePos); //we move the player's position
}
