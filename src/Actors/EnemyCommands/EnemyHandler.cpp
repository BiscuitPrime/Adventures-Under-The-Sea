/*
*	Source code for the enemy handler class
*/
#include <Actors/EnemyCommands/EnemyHandler.h>

//constructor
EnemyHandler::EnemyHandler() 
{
	_command = &moveCommand; //by default, enemy is on move command
}

//function that will control the enemy
void EnemyHandler::handleEnemy(Enemy* enemy, sf::RenderWindow* window)
{

}