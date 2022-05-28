#pragma once

#include <SFML/Graphics.hpp>
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
    sf::Texture sandTallTile;
    sf::Texture sandAlgeaTile;
    sf::Texture sandAlgea2Tile;
    sf::Texture sandAlgeaTallTile;
    sf::Texture sandAlgeaTall2Tile;
};

GameAssets* GameAssets::singleton = nullptr;

GameAssets::GameAssets() {
    std::string resourceDirectory = "../../../../resources/Sprites/";
    sandTile.loadFromFile(resourceDirectory + "sand.png");
    tileIndexes.insert({ "sand", sandTile });
    sandTallTile.loadFromFile(resourceDirectory + "sandTall.png");
    tileIndexes.insert({ "sandTall", sandTallTile });
    sandAlgeaTile.loadFromFile(resourceDirectory + "sandAlgea.png");
    tileIndexes.insert({ "sandAlgea", sandAlgeaTile });
    sandAlgea2Tile.loadFromFile(resourceDirectory + "sandAlgea2.png");
    tileIndexes.insert({ "sandAlgea2", sandAlgea2Tile });
    sandAlgeaTallTile.loadFromFile(resourceDirectory + "sandAlgeaTall.png");
    tileIndexes.insert({ "sandAlgeaTall", sandAlgeaTallTile });
    sandAlgeaTall2Tile.loadFromFile(resourceDirectory + "sandAlgeaTall2.png");
    tileIndexes.insert({ "sandAlgeaTall2", sandAlgeaTall2Tile });
    
}