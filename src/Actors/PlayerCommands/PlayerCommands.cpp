#include "PlayerCommands.h"
/*
* Source code file for the Player Commands classes
*/

//---------------------------------------------------
//PlayerCommand class :
void PlayerCommand::execute(Player* player, sf::RenderWindow* window){}

//---------------------------------------------------
//Player's MoveCommand class :

//moving command for the player :
void MoveCommand::execute(Player* player, sf::RenderWindow* window)
{
	std::cout << "Move command executed\n";
	sf::Vector2i pixelMousePos = sf::Mouse::getPosition(*window); //get the current mouse position in the window
	sf::Vector2f worldMousePos = window->mapPixelToCoords(pixelMousePos);
	player->decreaseOxygen(1); //we decrease the player's oxygen
	std::cout << "Player oxygen :" << player->getOxygen()<<'\n';
	player->setPosition(worldMousePos); //we move the player's position
}

//---------------------------------------------------
//Player's AttackCommand class :

void MineAttackCommand::execute(Player* player, sf::RenderWindow* window)
{
	std::cout << "Mine Attack command executed\n";
}

void TorpedoAttackCommand::execute(Player* player, sf::RenderWindow* window)
{
	std::cout << "Torpedo Attack command executed\n";
}
