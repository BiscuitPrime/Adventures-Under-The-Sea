#pragma once
/*
*	Header for the Enemy Handler class, that will be used to command and control the enemy.
*/
#include <Actors/EnemyCommands/EnemyCommands.h>

class EnemyHandler {
private:
	EnemyCommand* _command; //command contains, at a point T in time, the NEXT command that will be called
	EnemyMoveCommand moveCommand;
	EnemyAttackCommand attackCommand;
public:
	EnemyHandler();
	void handleEnemy(Enemy* enemy, sf::RenderWindow* window);
};