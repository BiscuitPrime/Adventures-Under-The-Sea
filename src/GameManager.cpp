#include "GameManager.h"
#include "GameManager.h"
#include "GameManager.h"
#include "GameManager.h"
#include <GameManager.h>

/*
*	Source code for the Game Manager class
*/

//constructor of the game manager that handles the game.
GameManager::GameManager(int nid, Player* play, Enemy en, PlayerHandler* input, Tilemap* tilem, sf::RenderWindow* wind, GameAssets* ga) :
	id{nid},player{play},playerhandler{input},tilemap{tilem}, window{wind},gameAssets{ga}
{
	enemyGroup.push_back(en);
	_turn = PLAYER_TURN;
	currentEnemy = nullptr;
}

//function that handles the game loop :
void GameManager::gameLoop()
{
	//drawing the tilemap :
	tilemap->selectTile(*window, *gameAssets);

	//we determine who's turn it is :
	if (_turn == PLAYER_TURN)
	{
		//we start the player's turn :
		playerhandler->startPlayerLoop();

		//we handle the player's input :
		playerhandler->update(player, window, tilemap);

		if (playerhandler->finishedPlayerLoop())
		{
			//we then change turn :
			_turn = changeTurn();
		}
		//at the end of the player's turn, we remove the eventually dead enemies :
		for (auto it = enemyGroup.begin(); it < enemyGroup.end(); ++it)
		{
			if (it->getState() == STATE_DEAD)
			{
				enemyGroup.erase(it);
				if(enemyGroup.empty()) //if this triggers, it means the player killed all the enemies : we must end the level
				{ 
					isFinished = true;
				}
				break;
			}
		}
		//we check the player's oxygen :
		if (player->getOxygen() == 0) { player->death(); }
	}
	else if (_turn == ENEMY_TURN)
	{
		//we start the enemy's turn :
		if (currentEnemy == nullptr || currentEnemy->getEnemyLoopFinished()){ currentEnemy=selectEnemy(); }

		//we start the enemy's turn :
		currentEnemy->handleEnemy(player);

		//if the enemy has finished its actions :
		if (currentEnemy->getEnemyLoopFinished())
		{
			std::cout << "Enemy " << currentEnemy->getId()<<" turn has ended!\n";
			_turn = changeTurn();
		}
	}

	// ------------------------------- RENDER FUNCTION (should be created) ---------------------- =>
	render();
}


//functions that adds an enemy to the group of enemies stored in the Game Manager.
int GameManager::addEnemy(Enemy enemy)
{
	for (auto it = enemyGroup.begin(); it < enemyGroup.end(); ++it) //we remove the possibility of the system possessing 2 enemies with the same id ( 2 same enemies)
	{
		if (it->getId() == enemy.getId()) 
		{
			std::cout << "Error when assigning enemy to Game Manager : enemy with existing id already exists in the manager unit\n";
			return -1;
		}
	}
	enemyGroup.push_back(enemy); //we add the enemy to the list of enemies in the level
	//enemy.setUpEnemyOnTilemap(); //we tell the tilemap that it is occupied //PUT THIS INSIDE SPAWN FUNCTION OF ENEMY
	return 0;
}

//function that returns a random enemy of the game manager
Enemy* GameManager::selectEnemy()
{
	if (enemyGroup.size() <= 0) //if the enemy list is empty, we call the ending of the level
	{
		isFinished = true;
		return nullptr;
	}
	if (enemyGroup.size() == 1 && currentEnemy!=nullptr) //if the enemy list only contains one enemy, we always select it
	{
		return currentEnemy;
	}
	srand(time(0));  // Initialize random number generator.
	int curSelector = (rand() % enemyGroup.size());
	while (currentEnemy!=nullptr && enemyGroup.at(curSelector).getId() == currentEnemy->getId()) //we ensure no enemy is selected twice
	{
		curSelector = (rand() % enemyGroup.size());
		std::cout << "Selected enemy : " << enemyGroup.at(curSelector).getId() << "\n";
	}
	return &enemyGroup.at(curSelector);
}

//method that spawns the player at a given position
int GameManager::spawnPlayer(sf::Vector2i position)
{
	player->spawnPlayer(position);
	return 0;
}

//render function : 
void GameManager::render()
{
	tilemap->draw(*window); //drawing the tilemap
	window->draw(player->getSprite()); //drawing the player
	//drawing the enemies :
	for (auto it = enemyGroup.begin(); it < enemyGroup.end(); ++it)
	{
		window->draw(it->getSprite());
	}
	//enemy not drawn
	//we display the window :
	ImGui::SFML::Render(*window);
	window->display();
}
