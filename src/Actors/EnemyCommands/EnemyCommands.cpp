#include "EnemyCommands.h"
#include "EnemyCommands.h"
#include "EnemyCommands.h"
/*
*	Source code used for the enemy commands classes
*/

//-------------------------------------------------------------------------------------------------
// Enemy Command class :
void EnemyCommand::execute(Enemy* enemy, sf::RenderWindow* window) {}

//-------------------------------------------------------------------------------------------------
// Enemy Move Command class :

//move command
void EnemyMoveCommand::execute(Enemy* enemy, sf::RenderWindow* window)
{
	std::cout << "Enemy is moving !\n";
}

//-------------------------------------------------------------------------------------------------
// Enemy Attack Command class :
void EnemyAttackCommand::execute(Enemy* enemy, sf::RenderWindow* window)
{
	std::cout << "Enemy performing attack !\n";
}
