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
			_state = &PlayerStates::attack;
		}
		else if (_state == &PlayerStates::mine)
		{
			mineCommand.execute(player, window);
			_state = &PlayerStates::idle;
		}
		else if (_state == &PlayerStates::torpedo)
		{
			torpedoCommand.execute(player, window);
			_state = &PlayerStates::idle;
		}
	}

	//here we create a fake "change" that simulates the various game phases
	//We simulate the following state setup :
	// idle -> click A -> moving -> click mouse -> performs movement -> attack -> click M/T -> mine/torpedo -> click mouse -> perform attack -> idle
	// In the end product, the "click A" etc will be replaced by decisions made by the game system

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) //TO BE REMOVED EVENTUALLY
	{
		if (_state == &PlayerStates::idle) //if the player can move (A has been pressed) -> move if player can move
		{
			_state = &PlayerStates::moving;
		}
	}

	//same here
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) //TO BE REMOVED EVENTUALLY
	{
		if (_state == &PlayerStates::attack)
		{
			_state = &PlayerStates::mine;
		}
	}
	//same here
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))//TO BE REMOVED EVENTUALLY
	{
		if (_state == &PlayerStates::attack)
		{
			_state = &PlayerStates::torpedo;
		}
	}
}

//method that returns the current player state
PlayerState* InputHandler::getState()
{
	return _state;
}
