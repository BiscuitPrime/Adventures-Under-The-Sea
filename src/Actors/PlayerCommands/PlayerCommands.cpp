#include "PlayerCommands.h"
#include "PlayerCommands.h"
#include "PlayerCommands.h"
#include <Assets/Definitions.h>
/*
* Source code file for the Player Commands classes
*/

//---------------------------------------------------
//PlayerCommand class :
void PlayerCommand::execute(Player* player, sf::RenderWindow* window, Tile* selectedTile){}

Tile* PlayerCommand::getPrevSelectedTile()
{
	return prevSelectedTile;
}

void PlayerCommand::setPrevSelectedTile(Tile* tile)
{
	prevSelectedTile = tile;
}

//---------------------------------------------------
//Player's MoveCommand class :

//moving command for the player :
void MoveCommand::execute(Player* player, sf::RenderWindow* window, Tile* selectedTile)
{
	std::cout << "Move command executed\n";
	//we start by unallocating the prev tile :
	if(getPrevSelectedTile()!=NULL){
		getPrevSelectedTile()->changeOccupied(false);
		getPrevSelectedTile()->changeCurrentActor(nullptr);
	}
	//we recuperate the appropriate coords :
	sf::Vector2f isoCoords = Definitions::orthoToIso(sf::Vector2i(selectedTile->getOrthogonalCoords().x, selectedTile->getOrthogonalCoords().y));
	sf::Vector2f offset = { windowWidth / 2, windowHeight / 2 };
	sf::Vector2f worldCoords = isoCoords + offset; //we get the new player coords

	player->decreaseOxygen(1); //we decrease the player's oxygen
	std::cout << "Player oxygen :" << player->getOxygen()<<'\n';
	player->setPosition(worldCoords); //we move the player's position

	//we update the tile properties :
	selectedTile->changeCurrentActor(player);
	selectedTile->changeOccupied(true);
	//we change the previously selected tile to the current tile :
	setPrevSelectedTile(selectedTile);
}

//---------------------------------------------------
//Player's AttackCommand class :

void MineAttackCommand::execute(Player* player, sf::RenderWindow* window, Tile* selectedTile)
{
	std::cout << "Mine Attack command executed\n";
}

void TorpedoAttackCommand::execute(Player* player, sf::RenderWindow* window, Tile* selectedTile)
{
	std::cout << "Torpedo Attack command executed\n";
}
