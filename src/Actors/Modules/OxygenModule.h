#pragma once
#include <Assets/Definitions.h>
/*
*	Header used for the Oxygen module used by the Player
*/

class OxygenModule {
private:
	int oxygenCounter = 5;
	int maximalOxygen = MAX_OXYGEN;
	bool outOfOxygen = false;
public:
	OxygenModule() = default;
	void increaseOxygen(int value);
	void decreaseOxygen(int value);
	int getOxygen() const { return oxygenCounter;	}
	void setInitialOxygen(int initialValue)	{ oxygenCounter = initialValue; }
	bool checkOxygenStatus() const { return outOfOxygen; }
};