#include "Module.h"
/*
*	Source code for the Module class
*/

void Module::setInitialValue(int initialValue)
{
	if (initialValue > maximalValue)
	{
		std::cout << "error when initializing initial value of module "<<this->getType()<<'\n';
		exit(100);
	}
	valueCounter = initialValue;
}
