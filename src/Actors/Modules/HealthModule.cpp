#include <Actors/Modules/HealthModule.h>

//method that handles the takeDamage event of the player :
int HealthModule::takeDamage(int dmg)
{
	return hpCounter -= dmg;
}

void HealthModule::setInitialHealth(int hp)
{
	hpCounter = hp;
}

//method that returns the current hp
int HealthModule::getHealth()
{
	return hpCounter;
}
