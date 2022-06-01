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
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) //if the player is attempting to click and _state is moving -> we move the player
	{
		if (_state == &PlayerStates::moving)
		{
			_command = &moveCommand;
			_command->execute(player, window, &tilemap->getTile(tilemap->getSelectedTileCoords()->y,tilemap->getSelectedTileCoords()->x));
			_state = &PlayerStates::attack;
		}
		else if (_state == &PlayerStates::mine)
		{
			_command = &mineCommand;
			_command->execute(player, window, &tilemap->getTile(tilemap->getSelectedTileCoords()->y, tilemap->getSelectedTileCoords()->x));
			_state = &PlayerStates::idle;
		}
		else if (_state == &PlayerStates::torpedo)
		{
			_command = &torpedoCommand;
			_command->execute(player, window, &tilemap->getTile(tilemap->getSelectedTileCoords()->y, tilemap->getSelectedTileCoords()->x));
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
			int selectTiles = selectAvailableTiles(player, tilemap, 1);
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
	Tile* selectedTile = &tilemap->getTile(tilemap->getSelectedTileCoords()->y, tilemap->getSelectedTileCoords()->x);
	int tileIndX = 0;
	int tileIndY = 0;
	std::cout << "Selecting the tiles\n";
	while (tileIndX >= 0 && tileIndX < columns) 
	{
		while (tileIndY >= 0 && tileIndY < lines) 
		{
			Tile* curTile = &tilemap->getTile(player->getPosition().y - 1, player->getPosition().x - 1);
			int loadTextureVar = curTile->loadSelectedTextureVariant(gameAssets, MOVEMENT);
			if (loadTextureVar < 0) {
				std::cout << "Error when selecting tile: selected texture could not be loaded\n";
			}
			tileIndY += 1;
		}
		tileIndX += 1;
		std::cout << "Selection in progress : " << tileIndX << " , " << tileIndY<<'\n';
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
}

//method that returns the current player state
PlayerState* InputHandler::getState()
{
	return _state;
}
