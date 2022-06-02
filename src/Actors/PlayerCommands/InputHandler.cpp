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
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && tilemap->getTileRef(tilemap->getSelectedTileCoords())->getAvailable()) //if the player is attempting to click and _state is moving -> we move the player
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
			int selectTiles = selectAvailableTiles(player, tilemap, 2, _state); //we display the selectable tiles
			if (selectTiles == -1) { exit(0); }
		}
	}
	//same here
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) //TO BE REMOVED EVENTUALLY
	{
		std::cout << "M pressed\n";
		if (_state == &PlayerStates::attack)
		{
			_state = &PlayerStates::mine;
			std::cout << "Selecting mine tiles\n";
			int selectTiles = selectAvailableTiles(player, tilemap, 1, _state); //we display the selectable tiles
			if (selectTiles == -1) { exit(0); }
		}
	}
	//same here
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))//TO BE REMOVED EVENTUALLY
	{
		//std::cout << "T pressed\n";
		if (_state == &PlayerStates::attack)
		{
			_state = &PlayerStates::torpedo;
			std::cout << "Selecting torpedo tiles\n";
			int selectTiles = selectAvailableTiles(player, tilemap, 3, _state); //we display the selectable tiles
			if (selectTiles == -1) { exit(0); }
		}
	}
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
	
	Tile* selectedTile = tilemap->getTileRef(tilemap->getPlayerTile()->getOrthogonalCoords());
	std::cout << "Current selected player tile : " << tilemap->getPlayerTile()->getOrthogonalCoords().y << " , " << tilemap->getPlayerTile()->getOrthogonalCoords().x << '\n';
	
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
	if (loadTextureVar < 0) //HERE --------------------------------------------------------------------- < -- Current crash
	{
		std::cout << "Error when selecting tile: selected texture could not be loaded\n";
		return -1;
	}
	selectedTile->setAvailable(true);

	//we will then select every tile around the player :
	for (int indX = -range; indX < range+1; indX++) 
	{
		for (int indY = -range; indY < range+1; indY++)
		{
			int y = tilemap->getPlayerTile()->getOrthogonalCoords().y + indY;
			int x = tilemap->getPlayerTile()->getOrthogonalCoords().x + indX;
			sf::Vector2i selectedCoords = sf::Vector2i(x, y);
			std::cout << x << " , " << y<<'\n';
			if ((std::abs(x - tilemap->getPlayerTile()->getOrthogonalCoords().x) + std::abs(y - tilemap->getPlayerTile()->getOrthogonalCoords().y)) <= 2) 
			{
				if (x >= 0 && x < lines && y >= 0 && y < columns) //we make sure that the selected tile is in bounds
				{
					selectedTile = tilemap->getTileRef(selectedCoords);
					if (_state == &PlayerStates::moving)
					{
						loadTextureVar = selectedTile->loadSelectedTextureVariant(gameAssets, MOVEMENT);
					}
					else if (_state == &PlayerStates::mine && _state == &PlayerStates::torpedo)
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
	if (int unselect = tilemap->unselectTiles(gameAssets) == -1) {
		std::cout << "Error while unselecting the Tiles (origin: InputHandler)\n";
		return -1;
	}
	return 0;
}

//method that sets up the player at the tilemap's 0,0 tile
void InputHandler::setUpPlayer(Player* player, Tilemap* tilemap)
{
	sf::Vector2i pos = sf::Vector2i(0, 0);
	sf::Vector2f isoCoords = Definitions::orthoToIsoWithOffset(pos);
	tilemap->getTile(pos).changeCurrentActor(player);
	tilemap->getTile(pos).changeOccupied(true);
}

//method that returns the current player state
PlayerState* InputHandler::getState()
{
	return _state;
}
