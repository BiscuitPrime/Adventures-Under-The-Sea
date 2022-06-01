#include "Enemy.h"
#include "Enemy.h"
/*
*	Source code of the Enemy class.
*/
#include <Actors/Enemy.h>

Enemy::Enemy(std::string texturePath) : Actor{ texturePath } 
{
	_state = EnemyStates::STATE_IDLE; //by default in idle state
	health.setInitialHealth(10);
}


//method called when the enemy is dying.
void Enemy::death() 
{
	std::cout << "Enemy has died.\n";
}

//returns the enemy current state
EnemyStates Enemy::getState()
{
	return _state;
}

//changes the enemy states to the inputted state
void Enemy::changeState(EnemyStates state)
{
	_state = state;
}
