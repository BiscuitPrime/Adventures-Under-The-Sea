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

int myMain()
{
    int width = 1920;
    int height = 1080;
    sf::RenderWindow window(sf::VideoMode(width, height), "SFML window");
    ImGui::SFML::Init(window);
    //---------------------------------
    //Creating the game elements :
    
    //Creating the game assets :
    auto ga = GameAssets();

    //Creating the player :
    std::string playerTexturePath = "../../../../resources/Sprites/Player.png";
    auto player = Player(0,playerTexturePath); //the player is created as a unique pointer

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
    auto gameManager = GameManager(&player, enemy, &inputHandler, &tilemap, &window, &ga);

    //adding another enemy :
    /*std::string enemyTexturePath2 = "../../../../resources/Sprites/EldritchSquidLeft.png";
    auto enemy2 = Enemy(2, enemyTexturePath, &tilemap);
    enemy2.spawn(sf::Vector2i(7, 7));
    int ret = gameManager.addEnemy(enemy2);
    if (ret == -1) { exit(0); }*/
    //---------------------------------

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
        gameManager.gameLoop();
    }

    ImGui::SFML::Shutdown();
    return 0;
}