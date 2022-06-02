/*
*	Source code for the enemy handler class
*/
#include <Actors/EnemyCommands/EnemyHandler.h>

//constructor
EnemyHandler::EnemyHandler() 
{
	_command = &moveCommand;
}

//function that will control the enemy
//this method is called by an exterior class when the enemy needs to do something
void EnemyHandler::handleEnemy(Enemy* enemy, sf::RenderWindow* window)
{
	if (enemy->getState() != STATE_IDLE) //if enemy is in movement state, handler calls the movement method
	{
		_command->execute();
		_command = &attackCommand; //we stock the next command
		enemy->nextState(); //we update the enemy's state
	}
}