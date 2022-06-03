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

//method that handles the internal enemy logic :
void Enemy::handleEnemy(sf::RenderWindow* window)
{
	if (_state == STATE_MOVING)
	{
		move();
	}
	else if (_state == STATE_ATTACK)
	{
		attack();
	}
}

void Enemy::move()
{
	std::cout << "Enemy performing movement !\n";
	_state = STATE_ATTACK;
}

void Enemy::attack()
{
	std::cout << "Enemy performing attack !\n";
	_state = STATE_IDLE;
	isEnemyLoopFinished = true;
}
