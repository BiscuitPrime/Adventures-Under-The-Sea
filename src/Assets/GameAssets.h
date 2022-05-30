#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class GameAssets {
private:
    static GameAssets* singleton;

    GameAssets();
public:
    static GameAssets* get() {
        // unique singleton pattern 
        if (!singleton)
            singleton = new GameAssets;
        return singleton;
    }

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

GameAssets* GameAssets::singleton = nullptr;

GameAssets::GameAssets() {
    std::string resourceDirectory = "resources/Sprites/";

    sandTile.loadFromFile(resourceDirectory + "sand.png");
    tileIndexes.insert({ "sand", sandTile });

    sandTileSelected.loadFromFile(resourceDirectory + "sandSelected.png");
    tileIndexes.insert({ "sandSelected", sandTileSelected });

    sandTallTileSelected.loadFromFile(resourceDirectory + "sandTall.png");
    tileIndexes.insert({ "sandTall", sandTallTile });

    sandTallTileSelected.loadFromFile(resourceDirectory + "sandTallSelected.png");
    tileIndexes.insert({ "sandTallSelected", sandTallTileSelected });

    sandAlgeaTile.loadFromFile(resourceDirectory + "sandAlgea.png");
    tileIndexes.insert({ "sandAlgea", sandAlgeaTile });

    sandAlgeaTileSelected.loadFromFile(resourceDirectory + "sandAlgeaSelected.png");
    tileIndexes.insert({ "sandAlgeaSelected", sandAlgeaTileSelected });

    sandAlgea2Tile.loadFromFile(resourceDirectory + "sandAlgea2.png");
    tileIndexes.insert({ "sandAlgea2", sandAlgea2Tile });

    sandAlgea2TileSelected.loadFromFile(resourceDirectory + "sandAlgea2Selected.png");
    tileIndexes.insert({ "sandAlgea2Selected", sandAlgea2TileSelected });

    sandAlgeaTallTile.loadFromFile(resourceDirectory + "sandAlgeaTall.png");
    tileIndexes.insert({ "sandAlgeaTall", sandAlgeaTallTile });

    sandAlgeaTallTileSelected.loadFromFile(resourceDirectory + "sandAlgeaTallSelected.png");
    tileIndexes.insert({ "sandAlgeaTallSelected", sandAlgeaTallTileSelected });

    sandAlgeaTall2Tile.loadFromFile(resourceDirectory + "sandAlgeaTall2.png");
    tileIndexes.insert({ "sandAlgeaTall2", sandAlgeaTall2Tile });

    sandAlgeaTall2TileSelected.loadFromFile(resourceDirectory + "sandAlgeaTall2Selected.png");
    tileIndexes.insert({ "sandAlgeaTall2Selected", sandAlgeaTall2TileSelected });
}