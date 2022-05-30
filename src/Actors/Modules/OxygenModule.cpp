#include "OxygenModule.h"
/*
* source code of the Oxygen Module
*/

//increases the OxygenModule's value
void OxygenModule::increaseOxygen(int value)
{
	oxygeneCounter += value;
}

//decreases the OxygenModule's value
void OxygenModule::decreaseOxygen(int value)
{
	oxygeneCounter -= value;
}

//returns the oxygen value
int OxygenModule::getOxygen()
{
	return oxygeneCounter;
}

//defines the first value of the oxygen module at its initialization
void OxygenModule::setInitialOxygen(int initialValue)
{
	oxygeneCounter = initialValue;
}
