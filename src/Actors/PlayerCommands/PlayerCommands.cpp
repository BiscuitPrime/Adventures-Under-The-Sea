#include "PlayerCommands.h"
#include "PlayerCommands.h"
#include "PlayerCommands.h"
#include <Assets/Definitions.h>
/*
* Source code file for the Player Commands classes
*/

//---------------------------------------------------
//PlayerCommand class :
void PlayerCommand::execute(Player* player, sf::RenderWindow* window, Tilemap* tilemap){}


//---------------------------------------------------
//Player's MoveCommand class :

//moving command for the player :
void MoveCommand::execute(Player* player, sf::RenderWindow* window, Tilemap* tilemap)
{
	std::cout << "Move command executed\n";
	//we recuperate the appropriate coords :
	sf::Vector2f isoCoords = Definitions::orthoToIso(sf::Vector2i(tilemap->getTileRef(tilemap->getSelectedTileCoords()->y, tilemap->getSelectedTileCoords()->x)->getOrthogonalCoords().x, tilemap->getTileRef(tilemap->getSelectedTileCoords()->y, tilemap->getSelectedTileCoords()->x)->getOrthogonalCoords().y));
	sf::Vector2f offset = { windowWidth / 2, windowHeight / 2 };
	sf::Vector2f worldCoords = isoCoords + offset; //we get the new player coords

	tilemap->removePlayerTile(); //we remove the old status for the previously occupied tile

	player->decreaseOxygen(1); //we decrease the player's oxygen
	std::cout << "Player oxygen :" << player->getOxygen()<<'\n';
	player->setPosition(worldCoords); //we move the player's position

	//we update the tile properties :
	Tile* selectedTile = tilemap->getTileRef(tilemap->getSelectedTileCoords()->y, tilemap->getSelectedTileCoords()->x);
	selectedTile->changeCurrentActor(player);
	selectedTile->changeOccupied(true);
}

//---------------------------------------------------
//Player's AttackCommand class :

void MineAttackCommand::execute(Player* player, sf::RenderWindow* window, Tilemap* tilemap)
{
	std::cout << "Mine Attack command executed\n";
}

void TorpedoAttackCommand::execute(Player* player, sf::RenderWindow* window, Tilemap* tilemap)
{
	std::cout << "Torpedo Attack command executed\n";
}
