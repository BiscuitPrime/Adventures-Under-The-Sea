#include "InputHandler.h"
#include "Assets/TilePatterns.h"
#include <imgui.h>

//constructor of the input handler :
InputHandler::InputHandler(GameAssets const& ga, UI* const& nui)
{
	ui = nui;
	gameAssets = ga;
	_state = &PlayerStates::idle; //by default, in idle state
	_command = &moveCommand; //by default, command is given to move command
}

//method that handles the player's inputs :
void InputHandler::handleInput(Player* player, sf::RenderWindow* window, Tilemap* tilemap) 
{
	TilePattern tilePatterns = TilePattern();
	// get selected tile, if left click is pressed and selected tile is available && accessible --> move
	if (auto selectedTile = tilemap->getTile(tilemap->getSelectedTileCoords()); sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && selectedTile->getAvailable() && selectedTile->getAccessibility()) //if the player is attempting to click and _state is moving -> we move the player
	{
		unselectAvailableTiles(tilemap); //we start by unloading any and all variants
		if (_state == &PlayerStates::moving)
		{
			_command = &moveCommand;
			_command->execute(player, window, tilemap);
			_state = &PlayerStates::attack;
		}
		else if (_state == &PlayerStates::mine)
		{
			_command = &mineCommand;
			_command->execute(player, window, tilemap);
			_state = &PlayerStates::idle;
			isPlayerLoopFinished = true; //by that point the player has finished its loop
		}
		else if (_state == &PlayerStates::torpedo)
		{
			_command = &torpedoCommand;
			_command->execute(player, window, tilemap);
			_state = &PlayerStates::idle;
			isPlayerLoopFinished = true; //by that point the player has finished its loop
		}
	}

	// ------------------------------------ IMGUI SEGMENT --------------------------------------------------
	
	// STATISTICS UI :
	ui->displayStatisticsUI(player->getHealth(), player->getOxygen());

	// WARNING UI :
	warningDisplay(player);

	//ACTION UI :
	ImGui::SetNextWindowPos(ImVec2(200, 20));
	ImGui::SetNextWindowSize(ImVec2(170, 100));
	ImGui::Begin("Choose Action :");
	if (ImGui::Button("Begin MOVEMENT"))
	{
		if (_state == &PlayerStates::idle) //if the player can move (A has been pressed) -> move if player can move
		{
			_state = &PlayerStates::moving;
			int selectTiles = selectAvailableArea(player->getCoordinates(), tilePatterns.sphere3, tilemap, MOVEMENT);
			//int selectTiles = selectAvailableTiles(player, tilemap, 3, _state); //we display the selectable tiles
			if (selectTiles == -1) { exit(0); }
		}
	}
	else if (ImGui::Button("Begin MINE")) 
	{
		std::cout << "Confirmed order : mine\n";
		if (_state == &PlayerStates::attack)
		{
			_state = &PlayerStates::mine;
			std::cout << "Selecting mine tiles\n";
			int selectTiles = selectAvailableArea(player->getCoordinates(), tilePatterns.adjacentTiles, tilemap, ATTACK);
			//int selectTiles = selectAvailableTiles(player, tilemap, 1, _state); //we display the selectable tiles
			if (selectTiles == -1) { exit(0); }
		}
	}
	else if (ImGui::Button("Begin TORPEDO"))
	{
		std::cout << "Confirmed order : torpedo\n";
		if (_state == &PlayerStates::attack)
		{
			_state = &PlayerStates::torpedo;
			std::cout << "Selecting torpedo tiles\n";
			int selectTiles = selectAvailableArea(player->getCoordinates(), tilePatterns.cross3, tilemap, ATTACK);
			//int selectTiles = selectAvailableTiles(player, tilemap, 2, _state); //we display the selectable tiles
			if (selectTiles == -1) { exit(0); }
		}
	}
	ImGui::End();
}

//method that will select the Available tiles dependant on the current player _state :
int InputHandler::selectAvailableArea(sf::Vector2i actorPos, std::vector<sf::Vector2i> relativeArea, Tilemap* tilemap, TileVariant variant)
{
	if (_state == &PlayerStates::idle) //test wether we are in correct state
	{
		std::cout << "Error when selecting available tiles : attempting to select available tiles in idle state\n";
		return -1;
	}
	if (relativeArea.size() <= 0) {
		std::cout << "Error when selecting available tiles : attempting to select null area\n";
		return -1;
	}
	if (variant != MOVEMENT && variant != ATTACK) {
		std::cout << "Error when selecting available tiles : only basic non Vanilla variants are allowed\n";
		return -1;
	}

	int loadTextureVar;
	for (auto pos : relativeArea) {
		auto target = actorPos + pos;
		if (target.x >= 0 && target.x < lines && target.y >= 0 && target.y < columns) {
			Tile* availableTile = tilemap->getTile(actorPos + pos);

			availableTile->setAvailable(true);
			availableTile->setVariant(variant);
			loadTextureVar = availableTile->loadTextureVariant(gameAssets);
			if (loadTextureVar < 0)
			{
				std::cout << "Error when selecting tile: selected texture could not be loaded\n";
				return -1;
			}
		}
	}
	return 0;
}

//method that will unselect the Available tiles dependant on the current player _state :
int InputHandler::unselectAvailableTiles(Tilemap* tilemap)
{
	if (int unselect = tilemap->removeAllTileVariants(gameAssets) == -1) {
		std::cout << "Error while unselecting the Tiles (origin: InputHandler)\n";
		return -1;
	}
	return 0;
}

//method that sets up the player at the tilemap's 0,0 tile
void InputHandler::setUpPlayer(Player* player, Tilemap* tilemap)
{
	sf::Vector2i pos = sf::Vector2i(0, 0);
	//sf::Vector2f isoCoords = Definitions::orthoToIsoWithOffset(pos);
	//two lines below had getTile
	tilemap->getTile(pos)->setCurrentActor(player);
	tilemap->getTile(pos)->setOccupied(true);
}

//method that will test wether or not the player needs to have a warning displayed
void InputHandler::warningDisplay(Player* player)
{
	if (player->getOxygen() <= OXYGEN_THRESHOLD)
	{
		std::string warningStr = "Oxygen";
		ui->warningOxygen();
	}
	if (player->getHealth() <= HEALTH_THRESHOLD)
	{
		std::string warningStr = "Health";
		ui->warningHealth((player->getOxygen()<= OXYGEN_THRESHOLD));
	}
}
