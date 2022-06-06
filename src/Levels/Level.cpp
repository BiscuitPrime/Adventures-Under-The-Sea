#include "Level.h"
/*
*	Source code for the level class
*/

//constructor
Level::Level(int id, GameManager* manager)
{
	gameManager = manager;
}

//function that sets up the player at a starting position in the level
int Level::initializeLevel()
{
	gameManager->initializePlayer();
	return 0;
}
