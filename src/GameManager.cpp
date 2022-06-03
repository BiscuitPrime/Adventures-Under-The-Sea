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
		//we start the player's turn :
		inputhandler->startPlayerLoop();

		//we handle the player's input :
		std::cout << "Player's turn !\n";
		inputhandler->handleInput(player, window, tilemap);

		if (inputhandler->finishedPlayerLoop())
		{
			//we then change turn :
			_turn = changeTurn();
		}
	}
	else if (_turn == ENEMY_TURN)
	{
		Enemy* currentEnemy;
		//we select the enemy that will perform the actions during this turn :
		std::cout << "Enemy's turn !\n";

		currentEnemy = &enemyGroup.front(); //FOR NOW the currently selected enemy will be the first of the list

		//we start the enemy's turn :
		currentEnemy->startEnemyLoop();
		currentEnemy->handleEnemy(window);

		//if the enemy has finished its actions :
		if (currentEnemy->getEnemyLoopFinished())
		{
			_turn = changeTurn();
		}
	}



	// RENDER FUNCTION (should be created) ---------------------- =>
	tilemap->draw(*window);
	window->draw(player->getSprite());
	//enemy not drawn
	//we display the window :
	window->display();
}

turnState GameManager::changeTurn()
{
	turnState _new_turn = _turn == PLAYER_TURN ? ENEMY_TURN : PLAYER_TURN;
	return _new_turn;
}
