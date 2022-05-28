#pragma once
/*
*	Header for the health module used by players.
*/

class HealthModule {
private:
	int hpCounter;
public:
	HealthModule(){};
	int takeDamage(int dmg); //takeDamage function, called by player and returns current life
	void setInitialHealth(int hp);
	int getHealth();
};