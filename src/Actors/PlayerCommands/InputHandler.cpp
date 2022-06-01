#include "InputHandler.h"
#include "InputHandler.h"
#include "InputHandler.h"
#include "InputHandler.h"
#include "InputHandler.h"
/*
* Source code for Input handler class
*/
#include <Actors/PlayerCommands/InputHandler.h>

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
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && ) //if the player is attempting to click and _state is moving -> we move the player
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
		}
		else if (_state == &PlayerStates::torpedo)
		{
			_command = &torpedoCommand;
			_command->execute(player, window, tilemap);
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
			int selectTiles = selectAvailableTiles(player, tilemap, 2); //we display the selectable tiles
			if (selectTiles == -1) { exit(0); }
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
//method that will select the Available tiles dependant on the current player _state :
//FOR NOW WORKS ONLY WITH _state = &PlayerStates::moving
int InputHandler::selectAvailableTiles(Player* player, Tilemap* tilemap, int range)
{
	if (_state == &PlayerStates::idle) //test wether we are in correct state
	{
		std::cout << "Error : attempting to select available tiles in idle state\n";
		return -1;
	}
	//we select the tile where the player currently is :
	
	Tile* selectedTile = tilemap->getTileRef(tilemap->getPlayerTile()->getOrthogonalCoords().y, tilemap->getPlayerTile()->getOrthogonalCoords().x);
	std::cout << "Current selected player tile : " << tilemap->getPlayerTile()->getOrthogonalCoords().y << " , " << tilemap->getPlayerTile()->getOrthogonalCoords().x << '\n';
	int loadTextureVar = selectedTile->loadSelectedTextureVariant(gameAssets, MOVEMENT);
	selectedTile->setAvailable(true);
	if (loadTextureVar < 0) {
		std::cout << "Error when selecting tile: selected texture could not be loaded\n";
	}
	//we will then select every tile around the player :
	for (int indX = -range; indX < range+1; indX++) 
	{
		for (int indY = -range; indY < range+1; indY++)
		{
			int y = tilemap->getPlayerTile()->getOrthogonalCoords().y + indY;
			int x = tilemap->getPlayerTile()->getOrthogonalCoords().x + indX;
			std::cout << x << " , " << y<<'\n';
			if ((std::abs(x - tilemap->getPlayerTile()->getOrthogonalCoords().x) + std::abs(y - tilemap->getPlayerTile()->getOrthogonalCoords().y)) <= 2) 
			{
				if (x >= 0 && x < lines && y >= 0 && y < columns) //we make sure that the selected tile is in bounds
				{
					selectedTile = tilemap->getTileRef(y, x);
					loadTextureVar = selectedTile->loadSelectedTextureVariant(gameAssets, MOVEMENT);
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
	if (int unselect = tilemap->unselectTiles(gameAssets) == -1) {
		std::cout << "Error while unselecting the Tiles (origin: InputHandler)\n";
		return -1;
	}
	return 0;
}

//method that sets up the player at the tilemap's 0,0 tile
void InputHandler::setUpPlayer(Player* player, Tilemap* tilemap)
{
	sf::Vector2i pos = tilemap->getTile(0, 0).getOrthogonalCoords();
	sf::Vector2f isoCoords = Definitions::orthoToIso(pos);
	sf::Vector2f offset = { windowWidth / 2, windowHeight / 2 };
	player->setPosition(isoCoords+offset);
	tilemap->getTile(0, 0).changeCurrentActor(player);
	tilemap->getTile(0, 0).changeOccupied(true);
}

//method that returns the current player state
PlayerState* InputHandler::getState()
{
	return _state;
}
