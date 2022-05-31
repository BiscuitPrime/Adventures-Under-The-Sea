#include <iostream>
#include <SFML/Graphics.hpp>
#include <World/Tilemap.h>
#include "myMain.h"
#include <SFML/Graphics.hpp>
#include <Actors/Player.h>
#include <Actors/PlayerCommands/InputHandler.h>
#include <Assets/Definitions.h>

int myMain()
{
    int width = 1920;
    int height = 1080;
    sf::RenderWindow window(sf::VideoMode(width, height), "SFML window");

    //---------------------------------
    //Creating the player :
    std::string playerTexturePath = "../../../../resources/Sprites/Player.png";
    auto player = Player(playerTexturePath);
    player.setPosition(sf::Vector2f(0, 0));
    //Creating the input handler associated to the player :
    auto inputHandler = InputHandler();
    //---------------------------------

    Tilemap tilemap;
    auto* fileName = (char*)"Tilemap.xml";
    auto ga = GameAssets();
    tilemap.buildTilemap(fileName, ga); // mettre dans le test
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //-------------------
        // CURRENTLY THE FOLLOWING CODE CREATES ISSUES :
        
        //inputHandler.handleInput(&player, &window); //each frame we call the inputhandler's handle input that will analyse the inputted data
        //window.draw(player.getSprite());
        //window.display();
        //--------------------
        
        tilemap.selectTile(window, ga);
    }

    return 0;
}