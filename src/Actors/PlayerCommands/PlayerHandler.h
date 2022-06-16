#pragma once
/*
* Header for the InputHandler class, that handles the analysis of the player's input and calls the appropriate commands that will execute functions
*/
#include <Actors/PlayerStates/PlayerStates.h>
#include <World/Tile.h>
#include <World/Tilemap.h>
#include <UI/UI.h>

class PlayerHandler {
private:
	PlayerState* _state; //state of the player
	GameAssets gameAssets;
	bool isPlayerLoopFinished = false;
	UI* ui;
public:
	explicit PlayerHandler(GameAssets const& ga, UI* const& ui);
	void update(Player* player, sf::RenderWindow* window, Tilemap* selectedTileCoords);
	int selectAvailableArea(sf::Vector2i actorPos, std::vector<sf::Vector2i> relativeArea, Tilemap* tilemap, TileVariant variant) const;
	int unselectAvailableTiles(Tilemap* tilemap) const;
	void setUpPlayer(Player* player, Tilemap* tilemap) const;
	PlayerState* getState() { return _state; };
	bool finishedPlayerLoop() const { return isPlayerLoopFinished; };
	void startPlayerLoop() { isPlayerLoopFinished = false; }
	void warningDisplay(Player* player);
	void inputUI() const;
};