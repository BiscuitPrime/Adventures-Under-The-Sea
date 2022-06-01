#pragma once
/*
* Header for the InputHandler class, that handles the analysis of the player's input and calls the appropriate commands that will execute functions
*/
#include <Actors/PlayerCommands/PlayerCommands.h>
#include <World/Tile.h>
#include <World/Tilemap.h>

static class InputHandler {
private:
	PlayerState* _state; //state of the player
	PlayerCommand* _command; //USELESS FOR NOW
	MoveCommand moveCommand;
	MineAttackCommand mineCommand;
	TorpedoAttackCommand torpedoCommand;
	GameAssets gameAssets;
	//Tile* currentSelectedTile;
public:
	explicit InputHandler(GameAssets const& ga);
	void handleInput(Player* player, sf::RenderWindow* window, Tilemap* selectedTileCoords);
	int selectAvailableTiles(Player* player, Tilemap* tilemap, int range, PlayerState* _state);
	int unselectAvailableTiles(Tilemap* tilemap);
	void setUpPlayer(Player* player, Tilemap* tilemap);
	PlayerState* getState();
};