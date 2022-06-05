#pragma once
#include "Strategy.h"
#include <SFML/Graphics.hpp>

class MovementStrategy : public Strategy {
public:
	virtual sf::Vector2i execute();
};