#include "GameManager.h"
#include "GameManager.h"
#include <GameManager.h>

/*
*	Source code for the Game Manager class
*/

//constructor of the game manager that handles the game.
GameManager::GameManager(Player* play, Enemy en, InputHandler* input, Tilemap* tilem, sf::RenderWindow* wind, GameAssets* ga)
{
	player = play;
	enemyGroup.push_back(en);
	inputhandler = input;
	window = wind;
	tilemap = tilem;
	gameAssets = ga;
	//previousTimestamp = high_resolution_clock::now();
	//lag = (duration<double>)0;
	_turn = PLAYER_TURN;
	currentEnemy = &en;
	en.setUpEnemyOnTilemap();
}

//function that handles the game loop :
void GameManager::gameLoop()
{
	/*
	//we calculate the elapsed time and lag to allow the game loop to take into accounts for various os's performances per the "Game Loop" Programming pattern
	high_resolution_clock::time_point currentTimestamp = high_resolution_clock::now();
	duration<double> elapsedTime = duration_cast<duration<double>>(currentTimestamp - previousTimestamp);
	previousTimestamp = currentTimestamp;
	lag += elapsedTime;
	std::cout << "lag : "<<lag<<'\n';
	*/

	//we clear the window :
	window->clear(sf::Color::Black);

	//drawing the tilemap :
	tilemap->selectTile(*window, *gameAssets);

	//IMGUI -----------------------------------------------------------------------------
	ImGui::Begin("Choose Action :");
	if (ImGui::Button("Begin MINE")) {
		cout << "Confirmed order : mine\n";
	}
	else if (ImGui::Button("Begin TORPEDO"))
	{
		cout << "Confirmed order : torpedo\n";
	}
	ImGui::End();

	//we determine who's turn it is :
	if (_turn == PLAYER_TURN)
	{
		//we start the player's turn :
		inputhandler->startPlayerLoop();

		//we handle the player's input :
		//std::cout << "Player's turn !\n";
		inputhandler->handleInput(player, window, tilemap);

		if (inputhandler->finishedPlayerLoop())
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
				break;
			}
		}
	}
	else if (_turn == ENEMY_TURN)
	{
		if (currentEnemy->getEnemyLoopFinished()){ currentEnemy=selectRandomEnemy(); }

		//we select the enemy that will perform the actions during this turn :
		//std::cout << "Enemy's turn !\n";

		//we start the enemy's turn :
		currentEnemy->handleEnemy(window);

		//if the enemy has finished its actions :
		if (currentEnemy->getEnemyLoopFinished())
		{
			std::cout << "Enemy " << currentEnemy->getId()<<" turn has ended!\n";
			_turn = changeTurn();
		}
	}

	// RENDER FUNCTION (should be created) ---------------------- =>
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

//method that returns the next turn depending on the current turn
turnState GameManager::changeTurn()
{
	return _turn == PLAYER_TURN ? ENEMY_TURN : PLAYER_TURN;
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
	enemy.setUpEnemyOnTilemap(); //we tell the tilemap that it is occupied //PUT THIS INSIDE SPAWN FUNCTION OF ENEMY
	return 0;
}

//function that returns a random enemy of the game manager
Enemy* GameManager::selectRandomEnemy()
{
	srand(time(0));  // Initialize random number generator.
	int curSelector = (rand()%enemyGroup.size());
	std::cout << "Selected enemy : " << enemyGroup.at(curSelector).getId() << "\n";
	return &enemyGroup.at(curSelector);
}

bool GameManager::isEnemyDead(Enemy enemy)
{
	if (enemy.getState() == STATE_DEAD) {
		return true;
	}
	return false;
}
