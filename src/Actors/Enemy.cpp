/*
*	Source code of the Enemy class.
*/
#include <Actors/Enemy.h>

Enemy::Enemy(std::string texturePath) : Actor{ texturePath } 
{}


//method called when the enemy is dying.
void Enemy::death() 
{
	std::cout << "Enemy has died.\n";
}