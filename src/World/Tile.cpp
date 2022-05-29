#include "Tile.h"
#include "Assets/Definitions.h"
#include "Assets/GameAssets.h"
#include <iostream>

Tile::Tile() :
xCoord(0),
yCoord(0),
texture("sand")
{
}

Tile::Tile(int x, int y, std::string str): 
xCoord(x),
yCoord(y),
texture(str)
{
}

void Tile::draw(sf::RenderWindow &window) const
{
    // creates sprite for the tile, sets its position, finds and loads texture from dictionnary in GameAssets.h
    sf::Sprite sprite;
    int width = window.getSize().x;
    int height = window.getSize().y;

    std::pair<int, int> isoCoords = Definitions::orthoToIso(std::pair<int, int>(getX(), getY()));
    std::pair<int, int> offset = { width / 2, height / 2 };
    sprite.setPosition(isoCoords.first + offset.first, isoCoords.second + offset.second);

    std::map<std::string, sf::Texture> tileIndexes = GameAssets::get()->tileIndexes;
    if (!tileIndexes.contains(texture)) {
        std::cout << "Error when drawing tile: texture \'" << texture << "\' could not be found\n";
    }
    else {
    sprite.setTexture(tileIndexes.at(getTexture()));
    window.draw(sprite);
    }
}
