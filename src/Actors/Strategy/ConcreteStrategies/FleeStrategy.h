#pragma once
#include <vector>
#include "MovementStrategy.h"
#include "Player.h"
#include "Enemy.h"

class FleeStrategy : public MovementStrategy {
public:
	sf::Vector2i execute(Enemy enemy, Player player, Tilemap tilemap) const {
		std::vector<sf::Vector2i> positions;
		sf::Vector2i currentEnnemyPos = enemy.getCoordinates();
		sf::Vector2i playerPos = player.getCoordinates();
		
		std::vector<sf::Vector2i> neighboringTiles = {sf::Vector2i(0, 1), sf::Vector2i(1, 0), sf::Vector2i(0, -1), sf::Vector2i(-1, 0) };
		int moves = 0;
		
		// find the next move that places the ennemy the further away for the player
		for (int moves = 0; moves < enemy.getMovementRange(); moves++) {
			// enemy can move over x tiles 
			int currentDistance = Definitions::manhattanDistance(playerpos, currentEnnemyPos);
			// test each adjacent tiles
			for (auto neighborPos : neighboringTiles) {
				sf::Vector2i potentialPos = currentEnnemyPos + neighborPos;
				int potentialDistance = Definitions::manhattanDistance(playerpos, potentialPos);
				// check if the tile is accessible, has no bubble and is further away from the player
				if (Tile* potentialTile = tilemap.getTile(potentialPos); potentialTile->getAccessibility() && !(potentialTile->hasBubble()) && potentialDistance > currentDistance) {
					positions.push_back(potentialPos);
					currentEnnemyPos = potentialPos;
				}
			}
		}
		return positions.end();
	}
};