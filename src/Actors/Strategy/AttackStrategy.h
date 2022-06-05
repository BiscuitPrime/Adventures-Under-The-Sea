#pragma once
#include "Strategy.h"
#include <vector>

class AttackStrategy : public Strategy {
	int damage;
	std::vector<sf::Vector2i> tilesAtRange;
public:
	AttackStrategy() = default;
	AttackStrategy(int dmg, std::vector<sf::Vector2i> tiles);
	int execute(sf::Vector2i enemyPos, sf::Vector2i playerPos) const;
	int getDamage() const { return damage; }
};