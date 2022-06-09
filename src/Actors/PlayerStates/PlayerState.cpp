#include "PlayerState.h"
#include <iostream>
/*
* Source code of the various player states
*/

//-------------------------------------------
//PlayerState class :
PlayerState::PlayerState() : stateName{ "playerState" } {}

void PlayerState::stateExecute(Player* player, sf::RenderWindow* window, Tilemap* tilemap){}
//-------------------------------------------

//-------------------------------------------
//PlayerIdleState class :
PlayerIdleState::PlayerIdleState() : stateName{ "playerIdleState" }{}

void PlayerIdleState::stateExecute(Player* player, sf::RenderWindow* window, Tilemap* tilemap)
{
	std::cout << "Idle state\n";
}

//-------------------------------------------

//-------------------------------------------
//PlayerMovingState class :
PlayerMovingState::PlayerMovingState(): stateName { "playerMovingState" } {}

void PlayerMovingState::stateExecute(Player* player, sf::RenderWindow* window, Tilemap* tilemap)
{
	std::cout << "Moving state\n";
	moveCommand.execute(player, window, tilemap);
}

//-------------------------------------------


//-------------------------------------------
//PlayerAttackState class :
PlayerAttackState::PlayerAttackState() :stateName{ "playerAttackState" } {}


void PlayerAttackState::stateExecute(Player* player, sf::RenderWindow* window, Tilemap* tilemap)
{
	std::cout << "Attack state\n";
}

//-------------------------------------------

//-------------------------------------------
//PlayerMineAttackState class :
PlayerMineAttackState::PlayerMineAttackState() : stateName{ "playerMineAttackState" } {}

void PlayerMineAttackState::stateExecute(Player* player, sf::RenderWindow* window, Tilemap* tilemap)
{
	std::cout << "Mine state\n";
	mineCommand.execute(player, window, tilemap);
}

//-------------------------------------------

//-------------------------------------------
//PlayerTorpedoAttackState class :
PlayerTorpedoAttackState::PlayerTorpedoAttackState() : stateName{ "playerTorpedoAttackState" } {}

void PlayerTorpedoAttackState::stateExecute(Player* player, sf::RenderWindow* window, Tilemap* tilemap)
{
	std::cout << "Torpedo state\n";
	torpedoCommand.execute(player, window, tilemap);
}