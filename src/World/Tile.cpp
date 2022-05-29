#include "Tile.h"
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

void Tile::draw(sf::RenderWindow &window)
{
    std::cout << "Draw tile (" << getX() << ", " << getY() << "\n";
    sf::Sprite sprite;
    int width = window.getSize().x;
    int height = window.getSize().y;
    std::pair<int, int> coords = { 64 * getX(), 64 * getY()};
    std::pair<int, int> isoCoords = { (coords.first - coords.second) * 0.5, (coords.first + coords.second) * 0.25 };
    std::pair<int, int> offset = { width / 2, height / 2 };
    sprite.setPosition(isoCoords.first + offset.first, isoCoords.second + offset.second);

    sprite.setTexture(GameAssets::get()->tileIndexes.at(getTexture()));

    window.draw(sprite);
}
