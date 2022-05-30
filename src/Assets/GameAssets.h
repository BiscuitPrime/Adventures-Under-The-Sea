#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class GameAssets {
public:
    GameAssets();
    // string to tile correspondence
    std::map<std::string, sf::Texture> tileIndexes;

    // sand tiles
    sf::Texture sandTile;
    sf::Texture sandTileSelected;
    sf::Texture sandTallTile;
    sf::Texture sandTallTileSelected;
    sf::Texture sandAlgeaTile;
    sf::Texture sandAlgeaTileSelected;
    sf::Texture sandAlgea2Tile;
    sf::Texture sandAlgea2TileSelected;
    sf::Texture sandAlgeaTallTile;
    sf::Texture sandAlgeaTallTileSelected;
    sf::Texture sandAlgeaTall2Tile;
    sf::Texture sandAlgeaTall2TileSelected;
};

