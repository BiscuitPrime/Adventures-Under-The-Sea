#include "Level.h"
/*
*	Source code for the level class
*/

//constructor
Level::Level(int nid, GameManager* manager, sf::Vector2i spawn) : id{nid}, gameManager{manager}, playerSpawn{spawn} {}

//function that sets up the player at a starting position in the level
int Level::initializeLevel()
{
	gameManager->spawnPlayer(playerSpawn);
	return 0;
}
