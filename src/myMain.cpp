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
    Tile* selectedTile = tilemap.getTile(0, 0);
    Tile* previouslySelectedTile = tilemap.getTile(0, 0);

    
    window.display();
    while (window.isOpen())
    {
        sf::Vector2i globalPosition = sf::Mouse::getPosition(window);
        sf::Vector2f worldPosition = window.mapPixelToCoords(globalPosition);
        //std::cout << "Mouse global pos : (" << globalPosition.x << ", " << globalPosition.y << ") || World Pos : (" << worldPosition.x << ", " << worldPosition.y << ")\n";
        previouslySelectedTile = selectedTile;
        selectedTile = tilemap.findNearestTileISO((int) worldPosition.x, (int)worldPosition.y);
        //std::cout << "Select tile (" << selectedTile->getOrthogonalCoords().x << ", " << selectedTile->getOrthogonalCoords().y << ")\n";
        previouslySelectedTile->unSelectTile();
        selectedTile->selectTile();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}