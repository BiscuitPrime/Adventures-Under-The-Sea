#include "PlayerState.h"
#include <Actors/PlayerStates/PlayerState.h>
#include <iostream>
/*
* Source code of the various player states
*/

//-------------------------------------------
//PlayerState class :
PlayerState::PlayerState() {
	stateName = "playerState";
}

void PlayerState::stateExecute() 
{}

std::string PlayerState::getName()
{
	return stateName;
}

//-------------------------------------------

//-------------------------------------------
//PlayerIdleState class :
PlayerIdleState::PlayerIdleState() 
{
	stateName = "playerIdleState";
}
void PlayerIdleState::stateExecute()
{
	std::cout << "Idle state\n";
}
std::string PlayerIdleState::getName()
{
	return stateName;
}
//-------------------------------------------

//-------------------------------------------
//PlayerMovingState class :
PlayerMovingState::PlayerMovingState() {
	stateName = "playerMovingState";
}

void PlayerMovingState::stateExecute()
{
	std::cout << "Moving state\n";
}
std::string PlayerMovingState::getName()
{
	return stateName;
}
//-------------------------------------------


//-------------------------------------------
//PlayerAttackState class :
PlayerAttackState::PlayerAttackState() {
	stateName = "playerAttackState";
}

void PlayerAttackState::stateExecute()
{
	std::cout << "Attack state\n";
}
std::string PlayerAttackState::getName()
{
	return std::string();
}
//-------------------------------------------

//-------------------------------------------
//PlayerMineAttackState class :
PlayerMineAttackState::PlayerMineAttackState() {
	stateName = "playerMineAttackState";
}

void PlayerMineAttackState::stateExecute()
{
	std::cout << "Mine state\n";
}
std::string PlayerMineAttackState::getName()
{
	return std::string();
}
//-------------------------------------------

//-------------------------------------------
//PlayerTorpedoAttackState class :
PlayerTorpedoAttackState::PlayerTorpedoAttackState() {
	stateName = "playerTorpedoAttackState";
}

void PlayerTorpedoAttackState::stateExecute()
{
	std::cout << "Torpedo state\n";
}

std::string PlayerTorpedoAttackState::getName()
{
	return std::string();
}
