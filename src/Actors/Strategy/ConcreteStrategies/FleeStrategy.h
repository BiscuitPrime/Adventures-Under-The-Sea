#pragma once
#include <vector>
#include <Actors/Strategy/MovementStrategy.h>

class FleeStrategy : public MovementStrategy {
public:
	FleeStrategy() {};
	sf::Vector2i execute(sf::Vector2i enemyPos, sf::Vector2i playerPos, Tilemap* tilemap, int movementRange) override {
		std::vector<sf::Vector2i> positions;
		sf::Vector2i currentEnnemyPos = enemyPos;
		// inital ennemy position is stored in case the ennemy won't move
		positions.push_back(currentEnnemyPos);

		std::vector<sf::Vector2i> neighboringTiles = {sf::Vector2i(0, 1), sf::Vector2i(1, 0), sf::Vector2i(0, -1), sf::Vector2i(-1, 0) };
		
		// find the next move that places the ennemy the further away for the player
		for (int moves = 0; moves < movementRange; moves++) {
			// enemy can move over x tiles 
			int currentDistance = Definitions::manhattanDistance(playerPos, currentEnnemyPos);
			// test each adjacent tiles
			for (auto neighborPos : neighboringTiles) {
				sf::Vector2i potentialPos = currentEnnemyPos + neighborPos;
				if (Definitions::positionIsWithinTilemapBounds(potentialPos)) {
					int potentialDistance = Definitions::manhattanDistance(playerPos, potentialPos);
					// check if the tile is accessible, has no bubble and is further away from the player
					if (Tile const* potentialTile = tilemap->getTile(potentialPos); potentialTile->getAccessibility() && !(potentialTile->hasBubble()) && potentialDistance > currentDistance) {
						positions.push_back(potentialPos);
						currentEnnemyPos = potentialPos;
					}
				}
			}
		}
		return positions.at(positions.size() - 1);
	}
};