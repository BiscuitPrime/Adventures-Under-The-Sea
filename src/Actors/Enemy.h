#pragma once
#include "Actor.h"
#include <iostream>
/*
* Enemy class
*/

class Enemy : public Actor {
public:
	Enemy(std::string texturePath);
	void death() override;
};