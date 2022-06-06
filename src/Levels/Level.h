#pragma once
/*
*	Header for the level class
*/
#include <Actors/Player.h>
#include <Assets/Definitions.h>
#include <GameManager.h>

class Level {
private:
	int id;
	GameManager* gameManager;
public:
	Level(int id, GameManager* gameManager);
	int getId() { return id; }
	GameManager* getGameManager() { return gameManager; };
	int initializeLevel();
};