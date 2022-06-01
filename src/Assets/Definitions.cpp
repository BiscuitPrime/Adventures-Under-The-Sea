#include "Definitions.h"

sf::Vector2f Definitions::orthoToIso(sf::Vector2i orthoCoords) {
	auto isoCoords = sf::Vector2f((orthoCoords.x - orthoCoords.y) * 0.5 * spriteSize, (orthoCoords.x + orthoCoords.y) * 0.25 * spriteSize);
	return isoCoords;
}

sf::Vector2f Definitions::isoToOrtho(sf::Vector2i isoCoords) {
	auto orthoCoords = sf::Vector2f( ((isoCoords.x + (2 * isoCoords.y)) / spriteSize), (((2 * isoCoords.y) - isoCoords.x) / spriteSize) );
	return orthoCoords;
}