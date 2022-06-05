#include "AttackStrategy.h"
#include <iostream>

AttackStrategy::AttackStrategy(int dmg, std::vector<sf::Vector2i> tiles) {
	damage = dmg;
	tilesAtRange = tiles;
}

int AttackStrategy::execute(sf::Vector2i enemyPos, sf::Vector2i playerPos) const {
	std::cout << "Potential damages : " << damage << "\n";
	for (auto tile : tilesAtRange) {
		sf::Vector2i target = enemyPos + tile;
		if (playerPos == target) {
			return damage;
		}
	}
	return 0;
}