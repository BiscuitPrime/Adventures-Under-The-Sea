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

Level* _currentLevel;
Level levelOne = Level(1,nullptr, sf::Vector2i(0,0));
Level levelTwo = Level(2, nullptr, sf::Vector2i(0, 0));

static void endLevel()
{
    _currentLevel = &levelTwo;
    _currentLevel->initializeLevel();
}

int myMain()
{
    //setting up the scene : // MAYBE MOVE THIS PART TO A SPECIAL SCENE SETTER ?
    int width = 1920;
    int height = 1080;
    sf::RenderWindow window(sf::VideoMode(width, height), GAME_NAME);
    ImGui::SFML::Init(window);
    // ------------------------------------------ Creating the game elements that exists outside of levels ----------------------------------------------------
    
    //Creating the game assets :
    auto ga = GameAssets();
    // Creating the UI :
    auto ui = UI(ga.AlertOxygen, ga.AlertHealth);

    //Creating the player :
    std::string playerTexturePath = "../../../../resources/Sprites/Player.png";
    auto player = Player(0, playerTexturePath); //the player is created as a unique pointer

    //Creating the input handler associated to the player :
    auto inputHandler = InputHandler(ga,&ui);

    // ------------------------------------------ Creating the game elements for the level 1 ------------------------------------------------------------------

    //Creating the tilemap :
    Tilemap tilemap;
    auto* fileName = (char*)"resources/tilemaps/TilemapLevel2.xml";
    tilemap.buildTilemap(fileName, ga); // mettre dans le test

    //Creating the basic enemy :
    std::string enemyTexturePath = "../../../../resources/Sprites/WyrmLeft.png";
    auto enemy = Enemy(1, enemyTexturePath, &tilemap);
    enemy.spawn(sf::Vector2i(7, 5));

    //setting up the player :
    inputHandler.setUpPlayer(&player, &tilemap);

    //Creating the game manager :
    auto gameManager = GameManager(1, &player, enemy, &inputHandler, &tilemap, &window, &ga);

    //adding another enemy :
    std::string enemyTexturePath2 = "../../../../resources/Sprites/EldritchSquidLeft.png";
    auto enemy2 = Enemy(2, enemyTexturePath2, &tilemap);
    enemy2.spawn(sf::Vector2i(7, 7));
    if (int ret = gameManager.addEnemy(enemy2); ret == -1) { exit(0); }

    // ------------------------------------------ Creating the game elements for the level 2 ------------------------------------------------------------------
    //Creating the basic enemy :
    std::string enemyTexturePath3 = "../../../../resources/Sprites/EnemyPLACEHOLDER.png";
    auto enemy3 = Enemy(3, enemyTexturePath3, &tilemap);
    enemy3.spawn(sf::Vector2i(7, 7));

    //Creating the game manager :
    auto gameManager2 = GameManager(1, &player, enemy3, &inputHandler, &tilemap, &window, &ga);

    // ------------------------------------------ Creating the levels ------------------------------------------------------------------
    //we create the level system that will control our game :
    levelOne = Level(1,&gameManager, sf::Vector2i(0,5));
    levelTwo = Level(2,&gameManager2, sf::Vector2i(0, 5));
    _currentLevel = &levelOne;
    bool started = false;

    //THE START MENU LOOP :
    sf::Clock deltaClock;
    while (window.isOpen() && started==false)
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

        //we create the game button :
        ImGui::SetNextWindowPos(ImVec2((windowWidth / 2)-100, (windowHeight / 2)));
        ImGui::SetNextWindowSize(ImVec2(200, 70));
        ImGui::Begin("Starting game");
        if(ImGui::Button("StartGame"))
        {
            started = true;
        }
        ImGui::End();
        ImGui::SFML::Render(window);
        window.display();
    }

    //THE MAIN GAME LOOP :
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

        //we call the game loop :
        _currentLevel->getGameManager()->gameLoop();
        if (_currentLevel->getGameManager()->getFinishedStatus()) { endLevel(); } //we test wether or not the level is finished
    }

    ImGui::SFML::Shutdown();
    return 0;
}