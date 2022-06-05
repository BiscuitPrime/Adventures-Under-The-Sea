#pragma once
#include <GameManager.h>

class LevelManager {
private:
	GameManager* _currentLevel;
	std::vector<GameManager> levels;
public:
	LevelManager();
	static int changeLevel();
	GameManager* getCurrentLevel();
};