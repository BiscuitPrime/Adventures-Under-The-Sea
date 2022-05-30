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
    auto* fileName = (char*) "Tilemap.xml"; // mettre dans le test
    tilemap.buildTilemap(fileName); // mettre dans le test
    tilemap.draw(window);
    Tile& selectedTile = tilemap.getTile(0, 0);
    Tile& previouslySelectedTile = tilemap.getTile(0, 0);

    
    window.display();
    while (window.isOpen())
    {
        sf::Vector2i worldPosition = sf::Mouse::getPosition(window);
        //std::cout << "World Pos : (" << worldPosition.x << ", " << worldPosition.y << ")\n";
        previouslySelectedTile = selectedTile;
        selectedTile = tilemap.findNearestTileISO((int) worldPosition.x, (int)worldPosition.y);
        //std::cout << "Select tile (" << selectedTile->getOrthogonalCoords().x << ", " << selectedTile->getOrthogonalCoords().y << ")\n";
        //previouslySelectedTile.unSelectTile();
        selectedTile.selectTile();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}