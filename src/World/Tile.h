#pragma once
#include "Assets/GameAssets.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Actors/Actor.h>
#include <Entities/Bubble.h>

enum TileVariant {
	VANILLA,
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
	std::string baseTexture;
	TileVariant currentVariant;
	sf::Texture texture;
	sf::Sprite sprite;
	Bubble* bubble;
	bool isSelected = false; 
	bool isAccessible = true; //whether the player can move on this tile or not
	bool isOccupied = false; //whether the tile is occupied by an entity
	bool isAvailable = false; //boolean indicating wether the tile should be displayed in an available manner or not
	bool isOccupiedByBubble = false;
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
	std::string getStringTexture() const { return baseTexture; }
	void setStringTexture(std::string str) { baseTexture = str; }
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
	void setOccupied(bool status) {	isOccupied = status; }
	void setCurrentActor(Actor* actor) { currentActor = actor; }
	bool getOccupied() const { return isOccupied; }
	Actor* getCurActor() const { return currentActor; }
	void setAccessibility(bool boolean) { isAccessible = boolean; }
	bool getAccessibility() const { return isAccessible; }
	void setAvailable(bool status) { isAvailable = status; }
	bool getAvailable() const { return isAvailable; }
	void setBubble(Bubble* bbl) { bubble = bbl;  }
	Bubble* getBubble() const { return bubble; }
	void setBubbleState(bool status) { isOccupiedByBubble = status; }
	bool hasBubble() const { return isOccupiedByBubble;  }
};
