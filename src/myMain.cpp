#include <iostream>
#include <SFML/Graphics.hpp>
#include <World/Tilemap.h>


int myMain()
{
    int width = 1920;
    int height = 1080;
    int columns = 10;
    int lines = 10;
    sf::RenderWindow window(sf::VideoMode(width, height), "SFML window");

    Tilemap tilemap;
    char* fileName = (char*) "Tilemap.xml";
    tilemap.buildTilemap(fileName);
    tilemap.draw(window);
    

    /*for (int x = 0; x < columns; x++) {
        for (int y = 0; y < lines; y++) {
            sf::Sprite sprite;
            sf::Texture texture = GameAssets::get()->tileIndexes.at("sandTall");
            sprite.setTexture(texture);
            sprite.setOrigin(sprite.getPosition().x - texture.getSize().x / 2, sprite.getPosition().y - texture.getSize().y / 2);
            std::pair<int, int> coords = { 64 * x, 64 * y };
            std::pair<int, int> isoCoords = { (coords.first - coords.second) * 0.5, (coords.first + coords.second) * 0.25 };
            std::pair<int, int> offset = { width / 2, height / 2 };
            sprite.setPosition(isoCoords.first + offset.first, isoCoords.second + offset.second);

            window.draw(sprite);
        }
    }*/
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