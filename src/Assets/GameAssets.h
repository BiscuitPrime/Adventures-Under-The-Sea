#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class GameAssets {
public:
    GameAssets();
    // string to tile correspondence
    std::map<std::string, sf::Texture> tileIndexes;

    // level 1 tiles (sand & algea)
    sf::Texture sandTile;
    sf::Texture sandTileMovement;
    sf::Texture sandTileSelected;
    sf::Texture sandTileMovementSelected;
    sf::Texture sandTallTile;
    sf::Texture sandTallTileMovement;
    sf::Texture sandTallTileSelected;
    sf::Texture sandTallTileMovementSelected;
    sf::Texture sandAlgeaTile;
    sf::Texture sandAlgeaTileMovement;
    sf::Texture sandAlgeaTileSelected;
    sf::Texture sandAlgeaTileMovementSelected;
    sf::Texture sandAlgea2Tile;
    sf::Texture sandAlgea2TileMovement;
    sf::Texture sandAlgea2TileSelected;
    sf::Texture sandAlgea2TileMovementSelected;
    sf::Texture sandAlgeaTallTile;
    sf::Texture sandAlgeaTallTileMovement;
    sf::Texture sandAlgeaTallTileSelected;
    sf::Texture sandAlgeaTallTileMovementSelected;
    sf::Texture sandAlgeaTall2Tile;
    sf::Texture sandAlgeaTall2TileMovement;
    sf::Texture sandAlgeaTall2TileSelected;
    sf::Texture sandAlgeaTall2TileMovementSelected;

    // level 3 tiles (sand & rocks)
    sf::Texture sandRockTile;
    sf::Texture sandRockTileMovement;
    sf::Texture sandRockTileSelected;
    sf::Texture sandRockTileMovementSelected;
    sf::Texture sandRockAlgeaTile;
    sf::Texture sandRockAlgeaTileMovement;
    sf::Texture sandRockAlgeaTileSelected;
    sf::Texture sandRockAlgeaTileMovementSelected;
    sf::Texture sandRock2Tile;
    sf::Texture sandRock2TileMovement;
    sf::Texture sandRock2TileSelected;
    sf::Texture sandRock2TileMovementSelected;
    sf::Texture sandRock2AlgeaTile;
    sf::Texture sandRock2AlgeaTileMovement;
    sf::Texture sandRock2AlgeaTileSelected;
    sf::Texture sandRock2AlgeaTileMovementSelected;
    sf::Texture sandRock3Tile;
    sf::Texture sandRock3TileMovement;
    sf::Texture sandRock3TileSelected;
    sf::Texture sandRock3TileMovementSelected;
    sf::Texture sandRock3AlgeaTile;
    sf::Texture sandRock3AlgeaTileMovement;
    sf::Texture sandRock3AlgeaTileSelected;
    sf::Texture sandRock3AlgeaTileMovementSelected;
};

