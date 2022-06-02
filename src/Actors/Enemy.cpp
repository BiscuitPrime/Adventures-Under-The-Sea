#include "Enemy.h"
/*
*	Source code of the Enemy class.
*/
#include <Actors/Enemy.h>

Enemy::Enemy(std::string texturePath) : Actor{ texturePath } 
{
	actorType = ENEMY;
	_state = EnemyStates::STATE_IDLE; //by default in idle state
	health.setInitialHealth(10);
}


//method called when the enemy is dying.
void Enemy::death() 
{
	std::cout << "Enemy has died.\n";
}

//method that returns the next state
void Enemy::nextState()
{
	if (_state == STATE_IDLE) { _state = STATE_MOVING; }
	else if (_state == STATE_MOVING) { _state = STATE_ATTACK; }
	else if (_state == STATE_ATTACK) { _state = STATE_IDLE; }
}