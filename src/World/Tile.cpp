#include "Tile.h"
#include "Assets/Definitions.h"
#include "Assets/GameAssets.h"
#include <iostream>

Tile::Tile() :
orthogonalCoords(sf::Vector2i(0, 0)),
isometricCoords(sf::Vector2i(0, 0)),
texture("sand")
{
}

Tile::Tile(int x, int y, std::string str): 
orthogonalCoords(sf::Vector2i(x, y)),
isometricCoords(sf::Vector2i(x, y)),
texture(str)
{
}

void Tile::draw(sf::RenderWindow &window)
{
    // finds and loads texture from dictionnary in GameAssets.
    // process sprite texture
    std::map<std::string, sf::Texture> tileIndexes = GameAssets::get()->tileIndexes;
    if (!tileIndexes.contains(texture)) {
        std::cout << "Error when drawing tile: texture \'" << texture << "\' could not be found\n";
    }
    else {
    sprite.setTexture(tileIndexes.at(getTexture()));
    //sets sprite position
    sprite.setPosition(sf::Vector2f(getIsometricCoords().x, getIsometricCoords().y));
    // draw
    window.draw(sprite);
    }
}

void Tile::selectTile(sf::RenderWindow& window)
{
    sprite.move(sf::Vector2f(0, 100));
    window.draw(sprite);
}

void Tile::unSelectTile(sf::RenderWindow& window)
{
    sprite.move(sf::Vector2f(0, -100));
    window.draw(sprite);
}
