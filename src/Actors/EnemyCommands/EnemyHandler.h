#pragma once
/*
*	Header for the Enemy Handler class, that will be used to command and control the enemy.
*/
#include <Actors/EnemyCommands/EnemyCommands.h>

class EnemyHandler {
private:
	EnemyCommand* _command;
	MoveCommand moveCommand;
	AttackCommand attackCommand;
public:
	EnemyHandler();
	void handleEnemy();
};