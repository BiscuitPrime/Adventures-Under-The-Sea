#include "LevelManager.h"
/*
*	Source code for the LevelManager class
*/

//constructor :
LevelManager::LevelManager(sf::RenderWindow* window)
{
	//we create here the various levels of the game : (MOVE THIS SOMEWHERE ELSE ?)
    // ----------------------------------------------- LEVEL 0 --------------------------------------------------
    //Creating the game elements for the level 1 :

    //Creating the game assets :
    auto ga = GameAssets();

    //Creating the player :
    std::string playerTexturePath = "../../../../resources/Sprites/Player.png";
    auto player = Player(0, playerTexturePath); //the player is created as a unique pointer

    //Creating the input handler associated to the player :
    auto inputHandler = InputHandler(ga);

    //Creating the tilemap :
    Tilemap tilemap;
    auto* fileName = (char*)"resources/tilemaps/Tilemap.xml";
    tilemap.buildTilemap(fileName, ga); // mettre dans le test

    //Creating the basic enemy :
    std::string enemyTexturePath = "../../../../resources/Sprites/EldritchSquidRight.png";
    auto enemy = Enemy(1, enemyTexturePath, &tilemap);
    enemy.spawn(sf::Vector2i(4, 5));

    //setting up the player :
    inputHandler.setUpPlayer(&player, &tilemap);

    //Creating the game manager :
    auto gameManager = GameManager(1,&player, enemy, &inputHandler, &tilemap, window, &ga);

    //adding another enemy :
    std::string enemyTexturePath2 = "../../../../resources/Sprites/EldritchSquidLeft.png";
    auto enemy2 = Enemy(2, enemyTexturePath, &tilemap);
    enemy2.spawn(sf::Vector2i(7, 7));
    int ret = gameManager.addEnemy(enemy2);
    if (ret == -1) { exit(0); }

    // ----------------------------------------------------------------------------------------------------------
    // ----------------------------------------------- LEVEL 1 --------------------------------------------------
    //auto levelOne = Level(1, &gameManager);

    // ----------------------------------------------------------------------------------------------------------
    //WE THEN set up the Levelmanager itself :
    levels.push_back(gameManager);
    //levels.push_back(levelOne);
    _currentLevel = &gameManager;
}

//we get the next level in the list of levels contained by LevelManager
int LevelManager::changeLevel()
{
	_currentLevel = &levels.at(static_cast<std::vector<GameManager, std::allocator<GameManager>>::size_type>(_currentLevel->getId()) + 1);
    return 0;
}

//returns the currently active level :
GameManager* LevelManager::getCurrentLevel()
{
	return _currentLevel;
}
