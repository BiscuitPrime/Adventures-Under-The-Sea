#pragma once
/*
*	Header containing the definition of the various Command classes implemented via the Command Game Programming Pattern
*/
#include <src/Actors/Player.h>

//basic PlayerCommand class :
class PlayerCommand {
public:
	virtual Command() {};
	virtual void execute(&Player player);
};

class MoveCommand :public PlayerCommand {
public:
	MoveCommand();

};

class AttackCommand :public PlayerCommand {
public:
	AttackCommand();
};