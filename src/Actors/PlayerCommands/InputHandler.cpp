/*
* Source code for Input handler class
*/
#include <Actors/PlayerCommands/InputHandler.h>


InputHandler::InputHandler()
{
	_state = &PlayerStates::idle; //by default, in idle state
}

//method that handles the player's inputs :
void InputHandler::handleInput(Player* player, sf::RenderWindow* window) 
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		if (_state == &PlayerStates::moving)
		{
			moveCommand.execute(player, window);
			_state = &PlayerStates::idle;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (_state == &PlayerStates::idle)
		{
			_state = &PlayerStates::moving;
		}
		else if (_state == &PlayerStates::moving)
		{
			_state = &PlayerStates::idle;
		}
	}
}
