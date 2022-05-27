#include "PlayerState.h"
#include <iostream>
/*
* Source code of the various player states
*/
void PlayerIdleState::handleInput()
{
	std::cout << "Idle state\n";
}

void PlayerMovingState::handleInput() 
{
	std::cout << "Moving state\n";
}

void PlayerAttackState::handleInput()
{
	std::cout << "Attack state\n";
}

void PlayerMineAttackState::handleInput()
{
	std::cout << "Mine state\n";
}

void PlayerTorpedoAttackState::handleInput()
{
	std::cout << "Torpedo state\n";
}