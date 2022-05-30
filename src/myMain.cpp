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
    tilemap.buildTilemap(fileName); // mettre dans le test
    Tile& selectedTile = tilemap.getTile(0, 0);
    Tile& previouslySelectedTile = tilemap.getTile(0, 0);

    tilemap.draw(window, ga);
    
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Vector2i worldPosition = sf::Mouse::getPosition(window);
        //std::cout << "World Pos : (" << worldPosition.x << ", " << worldPosition.y << ")\n";
        selectedTile = tilemap.findNearestTileISO((int)worldPosition.x, (int)worldPosition.y);
        tilemap.selectTile(selectedTile);
       
        window.clear(sf::Color::Black);
        tilemap.draw(window, ga);
        window.display();
    }

    return 0;
}