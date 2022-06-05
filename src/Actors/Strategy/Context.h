#pragma once
#include <MovementStrategy.h>
#include <AttackStrategy.h>

class Context {
private:
	MovementStrategy movementStrategy;
	AttackStrategy attackStrategy;
public: 
	void setStrategy();
	void executeMovementStrategy() const { movementStrategy.execute; }
	void executeAttackStrategy() const { attackStrategy.execute(); }
};