#include "PlayerCommands.h"
#include "PlayerCommands.h"
#include "PlayerCommands.h"
#include <Assets/Definitions.h>
/*
* Source code file for the Player Commands classes
*/

//---------------------------------------------------
//PlayerCommand class :
void PlayerCommand::execute(Player* player, sf::RenderWindow* window, Tilemap* tilemap){
	//virtual, hence empty
}


//---------------------------------------------------
//Player's MoveCommand class :

//moving command for the player :
void MoveCommand::execute(Player* player, sf::RenderWindow* window, Tilemap* tilemap)
{
	std::cout << "Move command executed\n";
	//we recuperate the appropriate coords :
	sf::Vector2i selectedTileCoords = tilemap->getSelectedTileCoords();
	sf::Vector2f worldCoords = Definitions::orthoToIsoWithOffset(selectedTileCoords);
	//we get the new player coords

	//we remove the old status for the previously occupied tile
	Tile* tile = tilemap->getTile(selectedTileCoords);
	tile->setCurrentActor(nullptr);
	tile->setOccupied(false);

	// oxygen management
	if (tile->hasBubble()) {
		player->increaseOxygen(5);
		tile->setBubbleState(false);
	}
	else {
		player->decreaseOxygen(1); //we decrease the player's oxygen
	}
	std::cout << "Player oxygen :" << player->getOxygen()<<'\n';
	// set player new positions
	player->setOrthoCoordinates(selectedTileCoords);
	player->setIsoCoordinates(worldCoords);
	player->getSprite().setPosition(worldCoords);


	//we update the tile properties :
	Tile* selectedTile = tilemap->getTile(tilemap->getSelectedTileCoords());
	selectedTile->setCurrentActor(player);
	selectedTile->setOccupied(true);
}

//---------------------------------------------------
//Player's MineAttackCommand class :

void MineAttackCommand::execute(Player* player, sf::RenderWindow* window, Tilemap* tilemap)
{
	std::cout << "Mine Attack command executed\n";
	sf::Vector2i selectedTileCoords = tilemap->getSelectedTileCoords();
	if (tilemap->getTile(selectedTileCoords)->getOccupied() && tilemap->getTile(selectedTileCoords)->getCurActor()->getType() == ENEMY) //if tile is occupied and contains an enemy, we attack that enemy
	{
		tilemap->getTile(selectedTileCoords)->getCurActor()->takeDamage(3);
	}
}

//---------------------------------------------------
//Player's MineAttackCommand class :

void TorpedoAttackCommand::execute(Player* player, sf::RenderWindow* window, Tilemap* tilemap)
{
	std::cout << "Torpedo Attack command executed\n";
	sf::Vector2i selectedTileCoords = tilemap->getSelectedTileCoords();
	if (tilemap->getTile(selectedTileCoords)->getOccupied() && tilemap->getTile(selectedTileCoords)->getCurActor()->getType() == ENEMY) //if tile is occupied and contains an enemy, we attack that enemy
	{
		tilemap->getTile(selectedTileCoords)->getCurActor()->takeDamage(1);
	}
}
