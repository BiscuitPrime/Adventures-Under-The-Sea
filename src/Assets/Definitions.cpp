#include "Definitions.h"
#include "Definitions.h"
#include "Definitions.h"

sf::Vector2f Definitions::orthoToIso(sf::Vector2i orthoCoords) {
	auto isoCoords = sf::Vector2f((orthoCoords.x - orthoCoords.y) * 0.5 * spriteSize, (orthoCoords.x + orthoCoords.y) * 0.25 * spriteSize);
	return isoCoords;
}

sf::Vector2f Definitions::orthoToIsoWithOffset(sf::Vector2i orthoCoords) {
	auto isoCoords = sf::Vector2f((orthoCoords.x - orthoCoords.y) * 0.5 * spriteSize, (orthoCoords.x + orthoCoords.y) * 0.25 * spriteSize);
	sf::Vector2f offset = { windowWidth / 2, windowHeight / 2 };
	return isoCoords + offset;
}

sf::Vector2f Definitions::isoToOrtho(sf::Vector2i isoCoords) {
	auto orthoCoords = sf::Vector2f(((isoCoords.x + (2 * isoCoords.y)) / spriteSize), (((2 * isoCoords.y) - isoCoords.x) / spriteSize));
	return orthoCoords;
}

sf::Vector2f Definitions::isoToOrthoWithOffset(sf::Vector2i isoCoords) {
	sf::Vector2i offset = { windowWidth / 2, windowHeight / 2 };
	sf::Vector2i isoCoordsNoOffset = isoCoords - offset;
	auto orthoCoords = sf::Vector2f(((isoCoords.x + (2 * isoCoords.y)) / spriteSize), (((2 * isoCoords.y) - isoCoords.x) / spriteSize));
	return orthoCoords;
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
