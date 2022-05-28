#include <Actors/PlayerStates/PlayerState.h>
#include <iostream>
/*
* Source code of the various player states
*/

//-------------------------------------------
//PlayerState class :
PlayerState::PlayerState() {}

void PlayerState::handleStateInput() {}
//-------------------------------------------

//-------------------------------------------
//PlayerIdleState class :
PlayerIdleState::PlayerIdleState() {}


void PlayerIdleState::handleStateInput()
{
	std::cout << "Idle state\n";
}
//-------------------------------------------

//-------------------------------------------
//PlayerMovingState class :
PlayerMovingState::PlayerMovingState() {}

void PlayerMovingState::handleStateInput()
{
	std::cout << "Moving state\n";
}
//-------------------------------------------

//-------------------------------------------
//PlayerAttackState class :
PlayerAttackState::PlayerAttackState() {}

void PlayerAttackState::handleStateInput()
{
	std::cout << "Attack state\n";
}
//-------------------------------------------

//-------------------------------------------
//PlayerMineAttackState class :
PlayerMineAttackState::PlayerMineAttackState() {}

void PlayerMineAttackState::handleStateInput()
{
	std::cout << "Mine state\n";
}
//-------------------------------------------

//-------------------------------------------
//PlayerTorpedoAttackState class :
PlayerTorpedoAttackState::PlayerTorpedoAttackState() {}

void PlayerTorpedoAttackState::handleStateInput()
{
	std::cout << "Torpedo state\n";
}
