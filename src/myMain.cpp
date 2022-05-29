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
    auto* fileName = (char*) "Tilemap.xml";
    tilemap.buildTilemap(fileName);
    tilemap.draw(window);
    
    window.display();
    while (window.isOpen())
    {
        sf::Vector2i globalPosition = sf::Mouse::getPosition(window);
        sf::Vector2f worldPosition = window.mapPixelToCoords(globalPosition);
        //std::cout << "Mouse global pos : (" << globalPosition.x << ", " << globalPosition.y << ") || World Pos : (" << worldPosition.x << ", " << worldPosition.y << ")\n";
        std::pair<int, int> gblPosition = std::pair(worldPosition.x, worldPosition.y);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}