#pragma once
#include "Actor.h"
#include <iostream>
/*
* Enemy class
*/

enum EnemyStates {
	STATE_IDLE,
	STATE_MOVING,
	STATE_ATTACK
};

class Enemy : public Actor {
private:
	EnemyStates _state;
public:
	Enemy(std::string texturePath);
	void death() override;
	EnemyStates getState();
	void nextState();
	void changeState(EnemyStates state);
};