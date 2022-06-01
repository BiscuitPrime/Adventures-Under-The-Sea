#pragma once
#include "Actor.h"
#include <iostream>
/*
* Enemy class
*/

enum class EnemyStates {
	STATE_IDLE,
	STATE_MOVING
};

class Enemy : public Actor {
private:
	EnemyStates _state;
public:
	Enemy(std::string texturePath);
	void death() override;
	EnemyStates getState();
	void changeState(EnemyStates state);
};