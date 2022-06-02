#include <GameManager.h>

/*
*	Source code for the Game Manager class
*/

//constructor of the game manager that handles the game.
GameManager::GameManager(Player* play, /*EnemyHandler en,*/ InputHandler* input, Tilemap* tilem, sf::RenderWindow* wind, GameAssets* ga)
{
	player = play;
	//enemyGroup.push_back(en);
	inputhandler = input;
	window = wind;
	tilemap = tilem;
	gameAssets = ga;
	//previousTimestamp = high_resolution_clock::now();
	//lag = (duration<double>)0;
	_turn = PLAYER_TURN;
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

	//we determine who's turn it is :
	if (_turn == PLAYER_TURN)
	{
		//we handle the player's input :
		inputhandler->handleInput(player, window, tilemap);
	}
	else if (_turn == ENEMY_TURN)
	{
		/*for (auto enemy = enemyGroup.begin(); enemy != enemyGroup.end(); ++enemy)
		{
			enemy->handleEnemy(window);
		}
		*/
	}

	// RENDER FUNCTION (should be created) ---------------------- =>
	tilemap->draw(*window);
	window->draw(player->getSprite());
	//we display the window :
	window->display();
}
