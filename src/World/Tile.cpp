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

//method that loads a variant texture :
int Tile::loadSelectedTextureVariant(GameAssets const& ga, TileVariant variant)
{
	std::map<std::string, sf::Texture> tileIndexes = ga.tileIndexes;
	switch (variant) {
	case SELECTED:
		if (!tileIndexes.contains(stringTexture + 's')) {
			std::cout << "Error when drawing tile: texture \'" << stringTexture + 's' << "\' could not be found (origin:Tile.cpp)\n";
			return -1;
		}
		setTexture(tileIndexes.at(stringTexture + 's'));
		sprite.setTexture(getTexture());
		return 0;
	case MOVEMENT:
		if (!tileIndexes.contains(stringTexture + 'm')) {
			std::cout << "Error when drawing tile: texture \'" << stringTexture + 'm' << "\' could not be found (origin:Tile.cpp)\n";
			return -1;
		}
		setTexture(tileIndexes.at(stringTexture + 'm'));
		sprite.setTexture(getTexture());
		return 0;
	case ATTACK:
		if (!tileIndexes.contains(stringTexture + 'a')) {
			std::cout << "Error when drawing tile: texture \'" << stringTexture + 'a' << "\' could not be found (origin:Tile.cpp)\n";
			return -1;
		}
		setTexture(tileIndexes.at(stringTexture + 'a'));
		sprite.setTexture(getTexture());
		return 0;
	case MOVEMENT_SELECTED:
		if (!tileIndexes.contains(stringTexture + "ms")) {
			std::cout << "Error when drawing tile: texture \'" << stringTexture + "ms" << "\' could not be found (origin:Tile.cpp)\n";
			return -1;
		}
		setTexture(tileIndexes.at(stringTexture + "ms"));
		sprite.setTexture(getTexture());
		return 0;
	case ATTACK_SELECTED:
		if (!tileIndexes.contains(stringTexture + "as")) {
			std::cout << "Error when drawing tile: texture \'" << stringTexture + "as" << "\' could not be found (origin:Tile.cpp)\n";
			return -1;
		}
		setTexture(tileIndexes.at(stringTexture + "as"));
		sprite.setTexture(getTexture());
		return 0;
	}
	return -1;
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





