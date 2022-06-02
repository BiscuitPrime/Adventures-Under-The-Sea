#include "EnemyHandler.h"
/*
*	Source code for the enemy handler class
*/

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
		_command = nextCommand(); //we stock the next command
		enemy->nextState(); //we update the enemy's state
	}
}

//function that returns the next command that the enemy will have to perform
EnemyCommand* EnemyHandler::nextCommand(EnemyCommand* curCommand)
{
	switch (curCommand) {
	case moveCommand:
		return attackCommand;
	case attackCommand:
		return moveCommand;
	default: //if curCommand doesn't enter the two previous cases, there's an issue
		std::cout << "Error : no current command for enemy (origin : EnemyHandler)\n";
		exit(0);
	}
}

