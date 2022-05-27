#pragma once
#include <SFML/Graphics.hpp>

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

    sf::Texture sandTile;
};

GameAssets* GameAssets::singleton = nullptr;

GameAssets::GameAssets() {
    sandTile.loadFromFile("C:/Users/hugoc/OneDrive/Documents/C++/projet/projet-cpp/resources/Sprites/sand.png");
}