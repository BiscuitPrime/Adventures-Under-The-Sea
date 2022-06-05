#include "InputHandler.h"
#include "InputHandler.h"
/*
* Source code for Input handler class
*/
#include <Actors/PlayerCommands/InputHandler.h>
#include <imgui.h>

//constructor of the input handler :
InputHandler::InputHandler(GameAssets const& ga)
{
	gameAssets = ga;
	_state = &PlayerStates::idle; //by default, in idle state
	_command = &moveCommand; //by default, command is given to move command
}

//method that handles the player's inputs :
void InputHandler::handleInput(Player* player, sf::RenderWindow* window, Tilemap* tilemap) 
{
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
	UI::displayStatisticsUI(player->getHealth(), player->getOxygen());

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
			int selectTiles = selectAvailableTiles(player, tilemap, 3, _state); //we display the selectable tiles
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
			int selectTiles = selectAvailableTiles(player, tilemap, 1, _state); //we display the selectable tiles
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
			int selectTiles = selectAvailableTiles(player, tilemap, 2, _state); //we display the selectable tiles
			if (selectTiles == -1) { exit(0); }
		}
	}
	ImGui::End();
}

//method that will select the Available tiles dependant on the current player _state :
int InputHandler::selectAvailableTiles(Player* player, Tilemap* tilemap, int range, PlayerState* _state)
{
	if (_state == &PlayerStates::idle) //test wether we are in correct state
	{
		std::cout << "Error : attempting to select available tiles in idle state\n";
		return -1;
	}
	//we select the tile where the player currently is :
	
	Tile* selectedTile = tilemap->getTile(player->getCoordinates());
	std::cout << "Current selected player tile : " << player->getCoordinates().x << " , " << player->getCoordinates().y << '\n';
	
	//we choose the current texture dependent on the state :
	int loadTextureVar;
	if (_state==&PlayerStates::moving)
	{
		tilemap->setAvailableVariant(MOVEMENT);
		loadTextureVar = selectedTile->loadSelectedTextureVariant(gameAssets, MOVEMENT);
	}
	else if (_state == &PlayerStates::mine || _state == &PlayerStates::torpedo)
	{
		tilemap->setAvailableVariant(ATTACK);
		loadTextureVar = selectedTile->loadSelectedTextureVariant(gameAssets, ATTACK);
	}

	if (loadTextureVar < 0) 
	{
		std::cout << "Error when selecting tile: selected texture could not be loaded\n";
		return -1;
	}

	selectedTile->setAvailable(true); //set's the tile availability

	//we will then select every tile around the player :
	for (int indX = -range; indX < range+1; indX++) 
	{
		for (int indY = -range; indY < range+1; indY++)
		{
			int y = player->getCoordinates().y + indY;
			int x = player->getCoordinates().x + indX;
			sf::Vector2i playerNeighborCoords = sf::Vector2i(x, y);
			std::cout << x << " , " << y<<'\n';
			if ((std::abs(x - player->getCoordinates().x) + std::abs(y - player->getCoordinates().y)) <= range)
			{
				if (x >= 0 && x < lines && y >= 0 && y < columns) //we make sure that the selected tile is in bounds
				{
					selectedTile = tilemap->getTile(playerNeighborCoords);
					if (_state == &PlayerStates::moving)
					{
						loadTextureVar = selectedTile->loadSelectedTextureVariant(gameAssets, MOVEMENT);
					}
					else if (_state == &PlayerStates::mine || _state == &PlayerStates::torpedo)
					{
						loadTextureVar = selectedTile->loadSelectedTextureVariant(gameAssets, ATTACK);
					}
					if (loadTextureVar < 0) {
						std::cout << "Error when selecting tile: selected texture could not be loaded\n";
					}
					selectedTile->setAvailable(true);
				}
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
	if (player->getOxygen() <= 2)
	{
		std::string warningStr = "Oxygen";
		UI::warning(warningStr);
	}
	if (player->getHealth() <= 3)
	{
		std::string warningStr = "Health";
		UI::warning(warningStr);
	}
}
