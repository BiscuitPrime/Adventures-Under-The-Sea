#pragma once
/*
*	Header used for the Oxygen module used by the Player
*/

class OxygenModule {
private:
	int oxygeneCounter;
public:
	OxygenModule() {};
	void increaseOxygen(int value);
	void decreaseOxygen(int value);
	int getOxygen();
	void setInitialOxygen(int initialValue);
};