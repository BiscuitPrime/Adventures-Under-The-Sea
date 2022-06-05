#include "MeleeAttackStrategy.h"
#include <iostream>

MeleeAttackStrategy::MeleeAttackStrategy(): AttackStrategy(2, { sf::Vector2i(1,0), sf::Vector2i(0,1), sf::Vector2i(-1,0), sf::Vector2i(0,-1) }){
}