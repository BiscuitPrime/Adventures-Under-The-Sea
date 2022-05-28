#pragma once
#include "PlayerState.h"
/*
* PlayerState class that contains the pointed references of the _state parameter of the player class
* Used by the Player class to indicate what state the player's in
*/
class PlayerStates {
public:
	static PlayerIdleState idle;
	static PlayerMovingState moving;
	static PlayerAttackState attack;
	static PlayerMineAttackState mine;
	static PlayerTorpedoAttackState torpedo;
};