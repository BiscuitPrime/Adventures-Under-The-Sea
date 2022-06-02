#pragma once
/*
*	Header for the Game Manager class that will be used to control the overall game systems.
*/
#include <chrono>
#include <iostream>
#include "Actors/Player.h"
#include "Actors/Enemy.h"
#include "Actors/PlayerCommands/InputHandler.h"
#include <Assets/GameAssets.h>

using namespace std;
using namespace std::chrono;

#define MS_PER_UPDATE (duration<double>)0.0007

class GameManager {
private:
	duration<double> lag;
	high_resolution_clock::time_point previousTimestamp;
	Player* player;
	Enemy* enemy;
	InputHandler* inputhandler;
	Tilemap* tilemap;
	sf::RenderWindow* window;
	GameAssets* gameAssets;
public:
	GameManager(Player* player, Enemy* enemy, InputHandler* inputHandler, Tilemap* tilemap, sf::RenderWindow* window, GameAssets* gameAssets);
	void gameLoop();
};