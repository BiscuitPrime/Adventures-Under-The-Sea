#pragma once
#include <Levels/Level.h>

class StartLevel : public Level {
public:
	StartLevel(int id, GameManager* gameManager);
	void startLoop(sf::RenderWindow* window) override;
};