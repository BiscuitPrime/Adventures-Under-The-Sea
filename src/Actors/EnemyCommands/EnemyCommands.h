#pragma once
/*
*	Header for the Enemy Command classes
* These classes contain the effective "functions" that will alter the enemy
*/
#include <Actors/Enemy.h>

//Basic enemy command class
class EnemyCommand {
public:
	EnemyCommand() {};
	virtual void execute(Enemy* enemy, sf::RenderWindow* window);
};

//Enemy move command class :
class MoveCommand : public EnemyCommand {
public:
	MoveCommand() {};
	void execute(Enemy* enemy, sf::RenderWindow* window) override;
};

//Enemy attack command class :
class AttackCommand : public EnemyCommand {
public:
	AttackCommand() {};
	void execute(Enemy* enemy, sf::RenderWindow* window) override;
};