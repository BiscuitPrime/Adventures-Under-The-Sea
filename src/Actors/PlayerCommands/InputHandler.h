#pragma once
/*
* Header for the InputHandler class
*/
#include <Actors/PlayerCommands/PlayerCommands.h>

static class InputHandler {
private:
	PlayerState* _state;
	MoveCommand moveCommand;
	AttackCommand attackCommand;
public:
	InputHandler();
	void handleInput(Player* player, sf::RenderWindow* window);
};