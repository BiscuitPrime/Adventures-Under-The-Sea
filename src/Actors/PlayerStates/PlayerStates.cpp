#include "Actors/PlayerStates/PlayerStates.h"
/*
* Source Code for the Player States class
*/

//Initialization of the various states object of the PlayerStates class :
PlayerIdleState PlayerStates::idle = PlayerIdleState();
PlayerMovingState PlayerStates::moving = PlayerMovingState();
/*
PlayerAttackState PlayerStates::attack = PlayerAttackState();
PlayerMineAttackState PlayerStates::mine = PlayerMineAttackState();
PlayerTorpedoAttackState PlayerStates::torpedo = PlayerTorpedoAttackState();
*/