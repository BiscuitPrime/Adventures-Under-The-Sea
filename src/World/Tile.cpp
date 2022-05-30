#include "Tile.h"
#include "Tile.h"
#include "Assets/Definitions.h"
#include <iostream>

Tile::Tile() :
orthogonalCoords(sf::Vector2i(0, 0)),
isometricCoords(sf::Vector2i(0, 0)),
texture("sand")
{
}

Tile::Tile(int x, int y, std::string str): 
orthogonalCoords(sf::Vector2i(x, y)),
isometricCoords(sf::Vector2i(0, 0)),
texture(str)
{
}

void Tile::draw(sf::RenderWindow &window, GameAssets ga)
{
    // finds and loads texture from dictionnary in GameAssets.
    // process sprite texture
    std::map<std::string, sf::Texture> tileIndexes = ga.tileIndexes;
    if (!tileIndexes.contains(texture)) {
        std::cout << "Error when drawing tile: texture \'" << texture << "\' could not be found\n";
    }
    else {
        sprite.setTexture(tileIndexes.at(texture));
        //sets sprite position
        sprite.setPosition(sf::Vector2f(getIsometricCoords().x, getIsometricCoords().y));
        // draw
        window.draw(sprite);
    }
}

void Tile::drawAsSelected(sf::RenderWindow& window, GameAssets ga)
{
    // finds and loads texture from dictionnary in GameAssets.
    std::string currentTexture = texture;
    currentTexture.append("s");
    // process sprite texture
    
    std::map<std::string, sf::Texture> tileIndexes = ga.tileIndexes;
    if (!tileIndexes.contains(currentTexture)) {
        std::cout << "Error when drawing tile: texture \'" << currentTexture << "\' could not be found\n";
    }
    else {
        sprite.setTexture(tileIndexes.at(currentTexture));
        //sets sprite position
        sprite.setPosition(sf::Vector2f(getIsometricCoords().x, getIsometricCoords().y));
        // draw
        window.draw(sprite);
    }
}
