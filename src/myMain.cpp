#include "myMain.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <World/Tilemap.h>
#include <SFML/Graphics.hpp>
#include <Actors/Player.h>
#include <Assets/Definitions.h>
#include <GameManager.h>
#include <../imgui/imgui.h>
#include <../imgui/imgui-SFML.h>
#include <Levels/Level.h>
#include "Levels/LevelManager.h"

int myMain()
{
    //setting up the scene : // MAYBE MOVE THIS PART TO A SPECIAL SCENE SETTER ?
    int width = 1920;
    int height = 1080;
    sf::RenderWindow window(sf::VideoMode(width, height), GAME_NAME);
    ImGui::SFML::Init(window);
    Level* _currentLevel;
    // ------------------------------------------ Creating the game elements for the level 1 ------------------------------------------------------------------

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
    auto gameManager = GameManager(1, &player, enemy, &inputHandler, &tilemap, &window, &ga);

    //adding another enemy :
    std::string enemyTexturePath2 = "../../../../resources/Sprites/EldritchSquidLeft.png";
    auto enemy2 = Enemy(2, enemyTexturePath, &tilemap);
    enemy2.spawn(sf::Vector2i(7, 7));
    int ret = gameManager.addEnemy(enemy2);
    if (ret == -1) { exit(0); }

    // ------------------------------------------ Creating the game elements for the level 2 ------------------------------------------------------------------
    //Creating the basic enemy :
    std::string enemyTexturePath3 = "../../../../resources/Sprites/EnemyPLACEHOLDER.png";
    auto enemy3 = Enemy(3, enemyTexturePath3, &tilemap);
    enemy3.spawn(sf::Vector2i(7, 7));

    //Creating the game manager :
    auto gameManager2 = GameManager(1, &player, enemy3, &inputHandler, &tilemap, &window, &ga);

    // ------------------------------------------ Creating the levels ------------------------------------------------------------------
    //we create the level system that will control our game :
    Level levelOne = Level(1,&gameManager);
    Level levelTwo = Level(2,&gameManager2);
    _currentLevel = &levelOne;

    sf::Clock deltaClock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        ImGui::SFML::Update(window, deltaClock.restart());

        // we call the game loop :
        _currentLevel->getGameManager()->gameLoop();

    }

    ImGui::SFML::Shutdown();
    return 0;
}