#include "Tile.h"
#include "Tile.h"
#include "Tile.h"
#include "Tile.h"
#include "Tile.h"
#include "Assets/Definitions.h"
#include <iostream>

Tile::Tile() :
orthogonalCoords(sf::Vector2i(0, 0)),
isometricCoords(sf::Vector2i(0, 0)),
stringTexture("sand")
{
}

Tile::Tile(int x, int y, std::string str): 
orthogonalCoords(sf::Vector2i(x, y)),
isometricCoords(sf::Vector2i(0, 0)),
stringTexture(str)
{
}

int Tile::loadSelectedTextureVariant(GameAssets const& ga)
{
	std::map<std::string, sf::Texture> tileIndexes = ga.tileIndexes;

	if (!tileIndexes.contains(stringTexture + 's')) {
		std::cout << "Error when drawing tile: texture \'" << stringTexture + 's' << "\' could not be found\n";
		return -1;
	}	
	setTexture(tileIndexes.at(stringTexture + 's'));
	sprite.setTexture(getTexture());
	return 0;
}

int Tile::unloadSelectedTextureVariant(GameAssets const& ga) {

	std::map<std::string, sf::Texture> tileIndexes = ga.tileIndexes;

	if (!tileIndexes.contains(stringTexture)) {
		std::cout << "Error when drawing tile: texture \'" << stringTexture << "\' could not be found\n";
		return -1;
	}
	setTexture(tileIndexes.at(stringTexture));
	sprite.setTexture(getTexture());
	return 0;
}

void Tile::draw(sf::RenderWindow &window)
{       // draw
        window.draw(sprite);
}

//changes the occupation status of the Tile
void Tile::changeOccupied(bool status)
{
	isOccupied = status;
}

//change the current actor on the tile :
void Tile::changeCurrentActor(Actor* actor)
{
	currentActor = actor;
}
