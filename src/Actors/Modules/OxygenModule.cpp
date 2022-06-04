#include "OxygenModule.h"
/*
* source code of the Oxygen Module
*/

//increases the OxygenModule's value
void OxygenModule::increaseOxygen(int value)
{
	oxygenCounter += value;
	if (oxygenCounter > maximalOxygen) oxygenCounter = maximalOxygen;
}

//decreases the OxygenModule's value
void OxygenModule::decreaseOxygen(int value)
{
	oxygenCounter -= value;
	if (oxygenCounter < 0) oxygenCounter = 0;
}

