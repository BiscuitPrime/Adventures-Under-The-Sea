#pragma once
#include <Actors/Modules/Module.h>
/*
*	Header used for the Oxygen module used by the Player
*/

class OxygenModule : public Module {
public:
	OxygenModule();
	void increaseOxygen(int value);
	void decreaseOxygen(int value);
};