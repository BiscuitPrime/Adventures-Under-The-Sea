#pragma once
/*
*	Header for the Game Manager class that will be used to control the overall game systems.
*/
#include <chrono>
#include <iostream>
#include <Actors/PlayerCommands/PlayerHandler.h>
#include <Assets/GameAssets.h>
#include "Actors/Enemy.h"
#include <ctime>
#include <cstdlib>
#include <../imgui/imgui.h>
#include <../imgui/imgui-SFML.h>

using namespace std;
using namespace std::chrono;

//#define MS_PER_UPDATE (duration<double>)0.09

enum turnState {
	PLAYER_TURN,
	ENEMY_TURN,
};

class GameManager {
private:
	int id;
	Player* player;
	std::vector<Enemy> enemyGroup;
	PlayerHandler* playerhandler;
	Tilemap* tilemap;
	sf::RenderWindow* window;
	GameAssets* gameAssets;
	turnState _turn; //indicates whose turn it is
	Enemy* currentEnemy; //indicates the enemy concerned by the current gameplay loop
	bool isFinished = false;
public:
	GameManager(int id,Player* player, Enemy enemy, PlayerHandler* inputHandler, Tilemap* tilemap, sf::RenderWindow* window, GameAssets* gameAssets);
	int getId() const { return id; };
	void gameLoop();
	turnState changeTurn() const { return _turn == PLAYER_TURN ? ENEMY_TURN : PLAYER_TURN; };
	int addEnemy(Enemy enemy);
	Enemy* selectEnemy();
	bool getFinishedStatus() const { return isFinished; };
	int spawnPlayer(sf::Vector2i position);
	void render();
};