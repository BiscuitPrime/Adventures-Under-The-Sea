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
#include <memory> 

Level* _currentLevel;
Level levelZero = Level(0, nullptr, sf::Vector2i(0, 0));
Level levelOne = Level(1, nullptr, sf::Vector2i(0, 0));

static void changeLevel()
{
    if (_currentLevel->getNextLevel()==nullptr) 
    {
        std::cout << "GAME OVER !\n";
        exit(0);
    }
    _currentLevel = _currentLevel->getNextLevel();
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
    sf::Texture playerTexture=ga.Player;
    auto player = Player(0, playerTexture); //the player is created as a unique pointer

    //Creating the input handler associated to the player :
    auto inputHandler = PlayerHandler(ga, &ui);

    // ------------------------------------------ Creating the game elements for the level 1 ------------------------------------------------------------------

    //Creating the tilemap :
    Tilemap tilemap;
    tilemap.buildTilemap((char*)"resources/tilemaps/TilemapLevel1.xml", ga); // mettre dans le test

    //Creating the basic enemy :
    sf::Texture enemyTexture = ga.EldritchSquidLeft;
    auto enemy = Enemy(1, enemyTexture, &tilemap, &ui);
    enemy.spawn(sf::Vector2i(7, 5));
    enemy.setName("Moth Birlith");

    //setting up the player :
    inputHandler.setUpPlayer(&player, &tilemap);

    //Creating the game manager :
    auto gameManager = GameManager(1, &player, &enemy, &inputHandler, &tilemap, &window, &ga);

    //adding another enemy :
    sf::Texture enemyTexture2 = ga.WyrmRight;
    auto enemy2 = Enemy(2, enemyTexture2, &tilemap, &ui);
    enemy2.spawn(sf::Vector2i(7, 7));
    enemy2.setName("Mavak");
    if (int ret = gameManager.addEnemy(&enemy2); ret == -1) { exit(0); }

    // ------------------------------------------ Creating the game elements for the level 2 ------------------------------------------------------------------
    //Creating the tilemap :
    Tilemap tilemap2;
    tilemap2.buildTilemap((char*)"resources/tilemaps/TilemapLevel2.xml", ga); // mettre dans le test

    //Creating the basic enemy :
    sf::Texture enemyTexture3 = ga.EldritchSquidRight;
    auto enemy3 = Enemy(3, enemyTexture3, &tilemap2, &ui);
    enemy3.spawn(sf::Vector2i(1, 8));
    enemy3.setName("Den Kavoth");

    //Creating the game manager :
    auto gameManager2 = GameManager(1, &player, &enemy3, &inputHandler, &tilemap2, &window, &ga);

    //adding another enemy :
    sf::Texture enemyTexture4 = ga.EldritchSquidLeft;
    auto enemy4 = Enemy(4, enemyTexture4, &tilemap2, &ui);
    enemy4.spawn(sf::Vector2i(5, 9));
    enemy4.setName("Oorb Nortis");
    if (int ret = gameManager2.addEnemy(&enemy4); ret == -1) { exit(0); }

    //adding another enemy :
    sf::Texture enemyTexture5 = ga.WyrmLeft;
    auto enemy5 = Enemy(5, enemyTexture5, &tilemap2, &ui);
    enemy5.spawn(sf::Vector2i(9, 6));
    enemy5.setName("Rene, stagiaire");
    if (int ret = gameManager2.addEnemy(&enemy5); ret == -1) { exit(0); }

    // ------------------------------------------ Creating the levels ------------------------------------------------------------------
    //we create the levels :
    levelZero = Level(0, &gameManager, sf::Vector2i(0, 5));
    levelOne = Level(1, &gameManager2, sf::Vector2i(4, 0));
    //we set up the next levels of each levels :
    levelZero.setNextLevel(&levelOne);
    levelOne.setNextLevel(nullptr);

    //WE SET the current active level, i.e. levelZero :
    levelZero.initializeLevel();
    _currentLevel = &levelZero;

    //boolean indicating wether start screen begun or not
    bool started = false;

    //THE START MENU LOOP :
    sf::Clock deltaClock;
    while (window.isOpen() && started == false)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        sf::Sprite titlescreen;
        titlescreen.setTexture(ga.Titlescreen);
        window.draw(titlescreen);
        ImGui::SFML::Update(window, deltaClock.restart());

        //we create the game button :
        ImGui::SetNextWindowPos(ImVec2(100, (WINDOW_HEIGHT / 2)));
        ImGui::SetNextWindowSize(ImVec2(200, 70));
        ImGui::Begin("Starting game");
        if (ImGui::Button("StartGame"))
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
        if (_currentLevel->getGameManager()->getFinishedStatus()) { changeLevel(); } //we test wether or not the level is finished
    }

    ImGui::SFML::Shutdown();
    return 0;
}