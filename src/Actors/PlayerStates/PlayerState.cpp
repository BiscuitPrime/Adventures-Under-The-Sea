#include <Actors/PlayerStates/PlayerState.h>
#include <iostream>
/*
* Source code of the various player states
*/

//-------------------------------------------
//PlayerState class :
PlayerState::PlayerState() {}

void PlayerState::stateExecute() {}
//-------------------------------------------

//-------------------------------------------
//PlayerIdleState class :
PlayerIdleState::PlayerIdleState() {}


void PlayerIdleState::stateExecute()
{
	std::cout << "Idle state\n";
}
//-------------------------------------------

//-------------------------------------------
//PlayerMovingState class :
PlayerMovingState::PlayerMovingState() {}

void PlayerMovingState::stateExecute()
{
	std::cout << "Moving state\n";
}
//-------------------------------------------


//-------------------------------------------
//PlayerAttackState class :
PlayerAttackState::PlayerAttackState() {}

void PlayerAttackState::stateExecute()
{
	std::cout << "Attack state\n";
}
//-------------------------------------------

//-------------------------------------------
//PlayerMineAttackState class :
PlayerMineAttackState::PlayerMineAttackState() {}

void PlayerMineAttackState::stateExecute()
{
	std::cout << "Mine state\n";
}
//-------------------------------------------

//-------------------------------------------
//PlayerTorpedoAttackState class :
PlayerTorpedoAttackState::PlayerTorpedoAttackState() {}

void PlayerTorpedoAttackState::stateExecute()
{
	std::cout << "Torpedo state\n";
}
