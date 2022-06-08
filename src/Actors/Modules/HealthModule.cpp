#include "HealthModule.h"
#include <Actors/Modules/HealthModule.h>

HealthModule::HealthModule()
{
	maximalValue = MAX_PLAYER_HEALTH;
	type = "Health Module";
}

//method that handles the takeDamage event of the player :
int HealthModule::takeDamage(int dmg)
{
	return valueCounter -= dmg;
}