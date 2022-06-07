#pragma once
/*
*	Header for the health module used by players.
*/
#include <Actors/Modules/Module.h>

class HealthModule : public Module {
private:
	int hpCounter;
public:
	HealthModule();
	int takeDamage(int dmg); //takeDamage function, called by player and returns current life
};