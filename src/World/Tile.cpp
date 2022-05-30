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
    // creates sprite for the tile, sets its position, finds and loads texture from dictionnary in GameAssets.h
    sf::Sprite sprite;
    int width = windowWidth;
    int height = windowHeight;
    // process isometric coordinates
    std::pair<int, int> isoCoords = Definitions::orthoToIso(std::pair<int, int>(orthogonalCoords.x, orthogonalCoords.y));
    std::pair<int, int> offset = { width / 2, height / 2 };
    sprite.setPosition(isoCoords.first + offset.first, isoCoords.second + offset.second);
    // store isometric coordinates
    setIsometricCoordinates(isoCoords.first + offset.first, isoCoords.second + offset.second);
    // process sprite texture
    std::map<std::string, sf::Texture> tileIndexes = GameAssets::get()->tileIndexes;
    if (!tileIndexes.contains(texture)) {
        std::cout << "Error when drawing tile: texture \'" << texture << "\' could not be found\n";
    }
    else {
    sprite.setTexture(tileIndexes.at(getTexture()));
    setSprite(sprite);
    // draw
    window.draw(sprite);
    }
}

void Tile::selectTile()
{
    std::cout << "Select tile (" << orthogonalCoords.x << ", " << orthogonalCoords.y << ")\n";
    sprite.move(sf::Vector2f(0, 100));
}

void Tile::unSelectTile()
{
    //std::cout << "Unselect tile (" << orthogonalCoords.x << ", " << orthogonalCoords.y << ")\n";
    sprite.move(sf::Vector2f(0, -100));
}
