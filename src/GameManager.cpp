#include <GameManager.h>

/*
*	Source code for the Game Manager class
*/

//constructor of the game manager that handles the game.
GameManager::GameManager(Player* play, Enemy* en, InputHandler* input, Tilemap* tilem, sf::RenderWindow* wind, GameAssets* ga)
{
	player = play;
	enemy = en;
	inputhandler = input;
	window = wind;
	tilemap = tilem;
	gameAssets = ga;
	previousTimestamp = high_resolution_clock::now();
	lag = (duration<double>)0;
}

//function that handles the game loop :
void GameManager::gameLoop()
{
	//we calculate the elapsed time and lag to allow the game loop to take into accounts for various os's performances per the "Game Loop" Programming pattern
	high_resolution_clock::time_point currentTimestamp = high_resolution_clock::now();
	duration<double> elapsedTime = duration_cast<duration<double>>(currentTimestamp - previousTimestamp);
	previousTimestamp = currentTimestamp;
	lag += elapsedTime;
	std::cout << "lag : "<<lag<<'\n';

	//we clear the window :
	window->clear(sf::Color::Black);

	//drawing the tilemap :
	tilemap->selectTile(*window, *gameAssets);


	while (lag >= MS_PER_UPDATE)
	{
		std::cout << "I'm in !\n";
		//we handle the player's input :
		inputhandler->handleInput(player, window, tilemap);
		lag -= MS_PER_UPDATE;
	}
	tilemap->draw(*window);
	window->draw(player->getSprite());
	// RENDER FUNCTION (should be created) ---------------------- =>
	//we display the window :
	window->display();
	/*
		//-------------------
		window.clear(sf::Color::Black);
		//drawing the tilemap :
		tilemap.selectTile(window, ga);
		tilemap.draw(window);
		//sf::Vector2i selectedTileCoords = tilemap.getSelectedTileCoords(); //we obtain the currently selected tile

		inputHandler.handleInput(&player, &window, &tilemap); //each frame we call the inputhandler's handle input that will analyse the inputted data and perform the appropriate player's action
		window.draw(enemy.getSprite());
		window.draw(player.getSprite());

		window.display();
		//--------------------
		*/
}
