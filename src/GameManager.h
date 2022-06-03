#pragma once
/*
*	Header for the Game Manager class that will be used to control the overall game systems.
*/
#include <chrono>
#include <iostream>
#include <Actors/PlayerCommands/InputHandler.h>
#include <Assets/GameAssets.h>
#include "Actors/Enemy.h"

using namespace std;
using namespace std::chrono;

//#define MS_PER_UPDATE (duration<double>)0.09

enum turnState {
	PLAYER_TURN,
	ENEMY_TURN,
};

class GameManager {
private:
	//duration<double> lag;
	//high_resolution_clock::time_point previousTimestamp;
	Player* player;
	std::vector<Enemy> enemyGroup;
	InputHandler* inputhandler;
	Tilemap* tilemap;
	sf::RenderWindow* window;
	GameAssets* gameAssets;
	turnState _turn;
	bool enemyLoop = false ;
public:
	GameManager(Player* player, Enemy enemy, InputHandler* inputHandler, Tilemap* tilemap, sf::RenderWindow* window, GameAssets* gameAssets);

	void gameLoop();
	turnState changeTurn();
};