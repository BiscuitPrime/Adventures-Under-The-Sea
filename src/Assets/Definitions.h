#pragma once

#include <utility>
#include <SFML/Graphics.hpp>

#define spriteSize 64							// size in px for the sprites
#define lines 10								// how many lines of tiles the tilemap has
#define columns 10								// how many columns of tiles the tilemap has 
#define windowWidth 1920						// width of the render window
#define windowHeight 1080						// height of the render window
#define MAX_OXYGEN 5							// max oxygen value
#define GAME_NAME "ADVENTURES UNDER THE SEA"	// name of the game
#define OXYGEN_THRESHOLD 2						// threshold indicating that oxygen is low
#define HEALTH_THRESHOLD 3						// threshold indicating that health is low

class Definitions {
// a class to hold tool functions
public:
	static sf::Vector2f orthoToIso(sf::Vector2i orthoCoords);
	static sf::Vector2f orthoToIsoWithOffset(sf::Vector2i orthoCoords);
	static sf::Vector2f isoToOrtho(sf::Vector2i isoCoords);
	static sf::Vector2f isoToOrthoWithOffset(sf::Vector2i isoCoords);
	static bool positionIsWithinTilemapBounds(sf::Vector2i position);
	static int manhattanDistance(sf::Vector2i A, sf::Vector2i B);
	static sf::Vector2i getRandomDirection();
};