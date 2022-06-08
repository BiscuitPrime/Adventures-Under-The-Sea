#include "OxygenModule.h"
#include "OxygenModule.h"
/*
* source code of the Oxygen Module
*/

OxygenModule::OxygenModule()
{
	maximalValue = MAX_OXYGEN;
	type = "OxygenModule";
}

//increases the OxygenModule's value
void OxygenModule::increaseOxygen(int value)
{
	valueCounter += value;
	if (valueCounter > maximalValue) 
	{ 
		valueCounter = maximalValue; 
	}
}

//decreases the OxygenModule's value
void OxygenModule::decreaseOxygen(int value)
{
	valueCounter -= value;
	if (valueCounter < 0) 
	{ 
		valueCounter = 0;
	}
}

