#include <iostream>
#include <SFML/Graphics.hpp>
#include <World/Tilemap.h>
#include "myMain.h"
#include <SFML/Graphics.hpp>
#include <Actors/Player.h>
#include <Actors/PlayerCommands/InputHandler.h>

int myMain()
{
    int width = 1920;
    int height = 1080;
    sf::RenderWindow window(sf::VideoMode(width, height), "SFML window");

    Tilemap tilemap;
    auto* fileName = (char*)"Tilemap.xml";
    tilemap.buildTilemap(fileName);
    tilemap.draw(window);

    window.display();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}