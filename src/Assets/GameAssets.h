#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class GameAssets {
public:
    GameAssets();
    // string to tile correspondence
    std::map<std::string, sf::Texture> tileIndexes;

    // actors
    sf::Texture EldritchSquidRight;
    sf::Texture EldritchSquidLeft;
    sf::Texture WyrmRight;
    sf::Texture WyrmLeft;

    // entities
    sf::Texture Bubble;

    // level 1 tiles (sand & algea)
    sf::Texture sandTile;
    sf::Texture sandTileAttack;
    sf::Texture sandTileMovement;
    sf::Texture sandTileSelected;
    sf::Texture sandTileAttackSelected;
    sf::Texture sandTileMovementSelected;
    sf::Texture sandTallTile;
    sf::Texture sandTallTileAttack;
    sf::Texture sandTallTileMovement;
    sf::Texture sandTallTileSelected;
    sf::Texture sandTallTileAttackSelected;
    sf::Texture sandTallTileMovementSelected;
    sf::Texture sandAlgeaTile;
    sf::Texture sandAlgeaTileAttack;
    sf::Texture sandAlgeaTileMovement;
    sf::Texture sandAlgeaTileSelected;
    sf::Texture sandAlgeaTileAttackSelected;
    sf::Texture sandAlgeaTileMovementSelected;
    sf::Texture sandAlgea2Tile;
    sf::Texture sandAlgea2TileAttack;
    sf::Texture sandAlgea2TileMovement;
    sf::Texture sandAlgea2TileSelected;
    sf::Texture sandAlgea2TileAttackSelected;
    sf::Texture sandAlgea2TileMovementSelected;
    sf::Texture sandAlgeaTallTile;
    sf::Texture sandAlgeaTallTileAttack;
    sf::Texture sandAlgeaTallTileMovement;
    sf::Texture sandAlgeaTallTileSelected;
    sf::Texture sandAlgeaTallTileAttackSelected;
    sf::Texture sandAlgeaTallTileMovementSelected;
    sf::Texture sandAlgeaTall2Tile;
    sf::Texture sandAlgeaTall2TileAttack;
    sf::Texture sandAlgeaTall2TileMovement;
    sf::Texture sandAlgeaTall2TileSelected;
    sf::Texture sandAlgeaTall2TileAttackSelected;
    sf::Texture sandAlgeaTall2TileMovementSelected;

    // level 3 tiles (sand & rocks)
    sf::Texture sandRockTile;
    sf::Texture sandRockTileAttack;
    sf::Texture sandRockTileMovement;
    sf::Texture sandRockTileSelected;
    sf::Texture sandRockTileAttackSelected;
    sf::Texture sandRockTileMovementSelected;
    sf::Texture sandRockAlgeaTile;
    sf::Texture sandRockAlgeaTileAttack;
    sf::Texture sandRockAlgeaTileMovement;
    sf::Texture sandRockAlgeaTileSelected;
    sf::Texture sandRockAlgeaTileAttackSelected;
    sf::Texture sandRockAlgeaTileMovementSelected;
    sf::Texture sandRock2Tile;
    sf::Texture sandRock2TileAttack;
    sf::Texture sandRock2TileMovement;
    sf::Texture sandRock2TileSelected;
    sf::Texture sandRock2TileAttackSelected;
    sf::Texture sandRock2TileMovementSelected;
    sf::Texture sandRock2AlgeaTile;
    sf::Texture sandRock2AlgeaTileAttack;
    sf::Texture sandRock2AlgeaTileMovement;
    sf::Texture sandRock2AlgeaTileSelected;
    sf::Texture sandRock2AlgeaTileAttackSelected;
    sf::Texture sandRock2AlgeaTileMovementSelected;
    sf::Texture sandRock3Tile;
    sf::Texture sandRock3TileAttack;
    sf::Texture sandRock3TileMovement;
    sf::Texture sandRock3TileSelected;
    sf::Texture sandRock3TileAttackSelected;
    sf::Texture sandRock3TileMovementSelected;
    sf::Texture sandRock3AlgeaTile;
    sf::Texture sandRock3AlgeaTileAttack;
    sf::Texture sandRock3AlgeaTileMovement;
    sf::Texture sandRock3AlgeaTileSelected;
    sf::Texture sandRock3AlgeaTileMovementSelected;
    sf::Texture sandRock3AlgeaTileAttackSelected;
};

