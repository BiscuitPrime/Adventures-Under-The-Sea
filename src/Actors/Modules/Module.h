#pragma once
/*
*	Header for the Module class, that can be used by entities. This serves as a template for health and oxygen modules.
*/
#include <Assets/Definitions.h>
#include <iostream>

class Module {
protected:
	int maximalValue;
	int valueCounter;
public:
	Module() = default;
	void setInitialValue(int initialValue);
	int getValue() const { return valueCounter; };
};