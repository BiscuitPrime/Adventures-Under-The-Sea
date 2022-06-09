#include "Definitions.h"
#include "Definitions.h"
#include "Definitions.h"
#include "Definitions.h"
/*
* Source code of the definitions
*/


sf::Vector2f Definitions::orthoToIso(sf::Vector2i orthoCoords) {
	auto isoCoords = sf::Vector2f((orthoCoords.x - orthoCoords.y) * 0.5 * SPRITE_SIZE, (orthoCoords.x + orthoCoords.y) * 0.25 * SPRITE_SIZE);
	return isoCoords;
}

sf::Vector2f Definitions::orthoToIsoWithOffset(sf::Vector2i orthoCoords) {
	auto isoCoords = sf::Vector2f((orthoCoords.x - orthoCoords.y) * 0.5 * SPRITE_SIZE, (orthoCoords.x + orthoCoords.y) * 0.25 * SPRITE_SIZE);
	sf::Vector2f offset = { WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 };
	return isoCoords + offset;
}

sf::Vector2f Definitions::isoToOrtho(sf::Vector2i isoCoords) {
	auto orthoCoords = sf::Vector2f(((isoCoords.x + (2 * isoCoords.y)) / SPRITE_SIZE), (((2 * isoCoords.y) - isoCoords.x) / SPRITE_SIZE));
	return orthoCoords;
}

sf::Vector2f Definitions::isoToOrthoWithOffset(sf::Vector2i isoCoords) {
	sf::Vector2i offset = { WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 };
	sf::Vector2i isoCoordsNoOffset = isoCoords - offset;
	auto orthoCoords = sf::Vector2f(((isoCoords.x + (2 * isoCoords.y)) / SPRITE_SIZE), (((2 * isoCoords.y) - isoCoords.x) / SPRITE_SIZE));
	return orthoCoords;
}

bool Definitions::positionIsWithinTilemapBounds(sf::Vector2i position)
{
	return (position.x >= 0 && position.x < 10 && position.y >= 0 && position.y < 10);
}

int Definitions::manhattanDistance(sf::Vector2i A, sf::Vector2i B)
{
	int xDistance = abs(B.x - A.x);
	int yDistance = abs(B.y - A.y);
	return xDistance + yDistance;
}

//method that returns a random direction
sf::Vector2i Definitions::getRandomDirection()
{
	srand(time(0));  // Initialize random number generator.
	int randX = (rand() % 3);
	int randXMinus = (rand() % 2);
	int randYMinus = (rand() % 2);
	int randY = (rand() % 3);
	if (randXMinus == 1) { randX = -randX; }
	if (randYMinus == 1) { randY = -randY; }
	return sf::Vector2i(randX,randY);
}
