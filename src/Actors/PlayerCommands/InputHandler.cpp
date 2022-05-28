/*
* Source code for Input handler class
*/
#include <Actors/PlayerCommands/InputHandler.h>

//constructor of the input handler :
InputHandler::InputHandler()
{
	_state = &PlayerStates::idle; //by default, in idle state
}

//method that handles the player's inputs :
void InputHandler::handleInput(Player* player, sf::RenderWindow* window) 
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) //if the player is attempting to click and _state is moving -> we move the player
	{
		if (_state == &PlayerStates::moving)
		{
			moveCommand.execute(player, window);
			_state = &PlayerStates::idle;
		}
	}

	//here we create a fake "change" that simulates the various game phases
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) //TO BE REMOVED EVENTUALLY
	{
		if (_state == &PlayerStates::idle)
		{
			_state = &PlayerStates::moving;
		}
	}
}
