#pragma once
#include "Actor.h"
#include <iostream>
/*
* Enemy class
*/

enum EnemyStates {
	STATE_IDLE,
	STATE_MOVING,
	STATE_ATTACK
};

class Enemy : public Actor {
private:
	int id;
	EnemyStates _state;
	bool isEnemyLoopFinished=true;
public:
	explicit Enemy(int id,std::string texturePath);
	void death() override;
	EnemyStates getState() const { return _state; };
	void nextState();
	void setState(EnemyStates state) { _state = state; };
	void handleEnemy(sf::RenderWindow* window);
	void move();
	void attack();
	bool getEnemyLoopFinished() const { return isEnemyLoopFinished; };
	void startEnemyLoop() { isEnemyLoopFinished = false; }
	int getId() const { return id; }
};