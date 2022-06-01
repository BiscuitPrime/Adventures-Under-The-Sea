#pragma once
#include "Assets/GameAssets.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Actors/Actor.h>

enum TileVariant {
	SELECTED,
	MOVEMENT,
	ATTACK,
	MOVEMENT_SELECTED,
	ATTACK_SELECTED,
};

class Tile {
/// <summary>
/// Tile has coordinates that describe its orthogonal position
/// Tile has a string describing its sf::Texture accordingly to the dictionnary in GameAssets.h
/// </summary>
private:
	sf::Vector2i orthogonalCoords;
	sf::Vector2i isometricCoords;
	std::string stringTexture;
	sf::Texture texture;
	sf::Sprite sprite;
	bool isSelected = false;
	bool isOccupied = false;
	Actor* currentActor; //currentActor on the tile
public:
	Tile();
	Tile(int x, int y, std::string str);
	void setCoordinates(int x, int y) {
		orthogonalCoords = sf::Vector2i(x, y);
	}
	void setIsometricCoordinates(int x, int y) {
		isometricCoords = sf::Vector2i(x, y);
	}
	std::string getStringTexture() const { return stringTexture; }
	void setStringTexture(std::string str) { stringTexture = str; }
	sf::Texture& getTexture() { return texture; }
	void setTexture(sf::Texture txtr) { texture = txtr; }
	sf::Sprite& getSprite() { return sprite; }
	void setSprite(sf::Sprite sprt) { sprite = sprt; }
	int loadSelectedTextureVariant(GameAssets const& ga, TileVariant tileVariant);
	int unloadSelectedTextureVariant(GameAssets const& ga);
	sf::Vector2i getOrthogonalCoords() const { return orthogonalCoords; }
	sf::Vector2i getIsometricCoords() const { return isometricCoords; }
	void selectTile() { isSelected = true; }
	void unselectTile() { isSelected = false; }
	void draw(sf::RenderWindow& window);
	void changeOccupied(bool status);
	void changeCurrentActor(Actor* actor);
};
