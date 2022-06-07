#include "HealthModule.h"
#include <Actors/Modules/HealthModule.h>

HealthModule::HealthModule()
{
}

//method that handles the takeDamage event of the player :
int HealthModule::takeDamage(int dmg)
{
	return hpCounter -= dmg;
}