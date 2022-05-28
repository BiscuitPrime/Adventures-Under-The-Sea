#pragma once
/*
* Header for the InputHandler class, that handles the analysis of the player's input and calls the appropriate commands that will execute functions
*/
#include <Actors/PlayerCommands/PlayerCommands.h>

static class InputHandler {
private:
	PlayerState* _state; //state of the player
	PlayerCommand* _command;
	MoveCommand moveCommand;
	MineAttackCommand mineCommand;
	TorpedoAttackCommand torpedoCommand;
public:
	InputHandler();
	void handleInput(Player* player, sf::RenderWindow* window);
	PlayerState* getState();
};