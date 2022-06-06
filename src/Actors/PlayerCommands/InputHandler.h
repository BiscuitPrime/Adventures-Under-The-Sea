#pragma once
/*
* Header for the InputHandler class, that handles the analysis of the player's input and calls the appropriate commands that will execute functions
*/
#include <Actors/PlayerCommands/PlayerCommands.h>
#include <World/Tile.h>
#include <World/Tilemap.h>
#include <UI/UI.h>

static class InputHandler {
private:
	PlayerState* _state; //state of the player
	PlayerCommand* _command; //USELESS FOR NOW
	MoveCommand moveCommand;
	MineAttackCommand mineCommand;
	TorpedoAttackCommand torpedoCommand;
	GameAssets gameAssets;
	//Tile* currentSelectedTile;
	bool isPlayerLoopFinished = false;
public:
	explicit InputHandler(GameAssets const& ga);
	void handleInput(Player* player, sf::RenderWindow* window, Tilemap* selectedTileCoords);
	int selectAvailableTiles(Player* player, Tilemap* tilemap, int range, PlayerState* _state);
	int selectAvailableArea(sf::Vector2i actorPos, std::vector<sf::Vector2i> relativeArea, Tilemap* tilemap, TileVariant variant);
	int unselectAvailableTiles(Tilemap* tilemap);
	void setUpPlayer(Player* player, Tilemap* tilemap);
	PlayerState* getState() { return _state; };
	bool finishedPlayerLoop() { return isPlayerLoopFinished; };
	void startPlayerLoop() { isPlayerLoopFinished = false; }
	void warningDisplay(Player* player);
};