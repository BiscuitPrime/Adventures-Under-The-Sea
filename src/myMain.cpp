#include <iostream>
#include <SFML/Graphics.hpp>
#include <World/Tilemap.h>
#include <Assets/Definitions.h>


int myMain()
{
    int width = 1920;
    int height = 1080;
    sf::RenderWindow window(sf::VideoMode(width, height), "SFML window");



    Tilemap tilemap;
    auto ga = GameAssets();
    auto* fileName = (char*) "Tilemap.xml"; // mettre dans le test
    tilemap.buildTilemap(fileName, ga); // mettre dans le test
   

    //tilemap.draw(window);
    
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        tilemap.selectTile(window, ga);
    }

    return 0;
}