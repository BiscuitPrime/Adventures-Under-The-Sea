#pragma once
/*
* Header for the InputHandler class
*/
#include <Actors/PlayerCommands/PlayerCommands.h>

static class InputHandler {
private:
	PlayerState* _state;
	MoveCommand moveCommand;
	MineAttackCommand mineCommand;
	TorpedoAttackCommand torpedoCommand;
public:
	InputHandler();
	void handleInput(Player* player, sf::RenderWindow* window);
	PlayerState* getState();
};