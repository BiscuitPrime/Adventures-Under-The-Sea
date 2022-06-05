#pragma once
#include <Actors/Strategy/AttackStrategy.h>

class RangeAttackStrategy : public AttackStrategy {
public:
	RangeAttackStrategy();
};

RangeAttackStrategy::RangeAttackStrategy(): 
	AttackStrategy(1, { sf::Vector2i(0,4), sf::Vector2i(1,4), sf::Vector2i(-1,4),
						sf::Vector2i(4,0), sf::Vector2i(4,1), sf::Vector2i(4,-1),
						sf::Vector2i(-4,0), sf::Vector2i(-4,1), sf::Vector2i(-4,-1),
						sf::Vector2i(0,-4), sf::Vector2i(1,-4), sf::Vector2i(-1,-4),
						sf::Vector2i(2,-3), sf::Vector2i(3,-2),
						sf::Vector2i(3, 2), sf::Vector2i(2,3),
						sf::Vector2i(-2,3), sf::Vector2i(-3,2), })
{
}