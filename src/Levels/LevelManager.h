#pragma once
#include <GameManager.h>

class LevelManager {
private:
	GameManager* _currentLevel;
	std::vector<GameManager> levels;
public:
	LevelManager(sf::RenderWindow* window);
	int changeLevel();
	GameManager* getCurrentLevel();
};