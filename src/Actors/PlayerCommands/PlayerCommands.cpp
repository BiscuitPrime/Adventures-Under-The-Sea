#include "PlayerCommands.h"
/*
* Source code file for the Player Commands classes
*/

//---------------------------------------------------
//PlayerCommand class :
void PlayerCommand::execute(Player* player, sf::RenderWindow* window){}

//---------------------------------------------------
//Player's MoveCommand class :

void MoveCommand::execute(Player* player, sf::RenderWindow* window)
{
	std::cout << "Move command launched\n";
	player->move(window);
}

//---------------------------------------------------
//Player's AttackCommand class :

void AttackCommand::execute(Player* player, sf::RenderWindow* window)
{
	std::cout << "Attack command launched\n";
}
