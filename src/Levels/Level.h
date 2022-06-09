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
	sf::Vector2i playerSpawn;
	Level* _nextlevel;
public:
	Level(int id, GameManager* gameManager, sf::Vector2i spawnPosition);
	int getId() { return id; }
	GameManager* getGameManager() { return gameManager; };
	int initializeLevel();
	Level* getNextLevel() const { return _nextlevel; };
	void setNextLevel(Level* level) { _nextlevel = level; }
};