#include "Tile.h"
#include "Assets/Definitions.h"
#include <iostream>

Tile::Tile() :
	orthogonalCoords(sf::Vector2i(0, 0)),
	isometricCoords(sf::Vector2i(0, 0)),
	baseTexture("sand"),
	currentVariant(TileVariant::VANILLA)
{
}

Tile::Tile(int x, int y, std::string str): 
orthogonalCoords(sf::Vector2i(x, y)),
isometricCoords(sf::Vector2i(0, 0)),
baseTexture(str)
{
}

//method that loads a variant texture :
int Tile::loadTextureVariant(GameAssets const& ga)
{
	std::map<std::string, sf::Texture> tileIndexes = ga.tileIndexes;
	switch (currentVariant) {
	case VANILLA:
		if (!tileIndexes.contains(baseTexture)) {
			std::cout << "Error when drawing tile: texture \'" << baseTexture + 's' << "\' could not be found (origin:Tile.cpp)\n";
			return -1;
		}
		setTexture(tileIndexes.at(baseTexture));
		sprite.setTexture(getTexture());
		return 0;
	case SELECTED:
		if (!tileIndexes.contains(baseTexture + 's')) {
			std::cout << "Error when drawing tile: texture \'" << baseTexture + 's' << "\' could not be found (origin:Tile.cpp)\n";
			return -1;
		}
		setTexture(tileIndexes.at(baseTexture + 's'));
		sprite.setTexture(getTexture());
		return 0;
	case MOVEMENT:
		if (!tileIndexes.contains(baseTexture + 'm')) {
			std::cout << "Error when drawing tile: texture \'" << baseTexture + 'm' << "\' could not be found (origin:Tile.cpp)\n";
			return -1;
		}
		setTexture(tileIndexes.at(baseTexture + 'm'));
		sprite.setTexture(getTexture());
		return 0;
	case ATTACK:
		if (!tileIndexes.contains(baseTexture + 'a')) {
			std::cout << "Error when drawing tile: texture \'" << baseTexture + 'a' << "\' could not be found (origin:Tile.cpp)\n";
			return -1;
		}
		setTexture(tileIndexes.at(baseTexture + 'a'));
		sprite.setTexture(getTexture());
		return 0;
	case MOVEMENT_SELECTED:
		if (!tileIndexes.contains(baseTexture + "ms")) {
			std::cout << "Error when drawing tile: texture \'" << baseTexture + "ms" << "\' could not be found (origin:Tile.cpp)\n";
			return -1;
		}
		setTexture(tileIndexes.at(baseTexture + "ms"));
		sprite.setTexture(getTexture());
		return 0;
	case ATTACK_SELECTED:
		if (!tileIndexes.contains(baseTexture + "as")) {
			std::cout << "Error when drawing tile: texture \'" << baseTexture + "as" << "\' could not be found (origin:Tile.cpp)\n";
			return -1;
		}
		setTexture(tileIndexes.at(baseTexture + "as"));
		sprite.setTexture(getTexture());
		return 0;
	}
	return -1;
}

int Tile::unloadTextureVariant(GameAssets const& ga) {

	std::map<std::string, sf::Texture> tileIndexes = ga.tileIndexes;

	if (!tileIndexes.contains(baseTexture)) {
		std::cout << "Error when drawing tile: texture \'" << baseTexture << "\' could not be found\n";
		return -1;
	}

	texture = tileIndexes.at(baseTexture);
	currentVariant = VANILLA;
	sprite.setTexture(getTexture());
	return 0;
}

void Tile::draw(sf::RenderWindow &window)
{       // draw
        window.draw(sprite);
		if (isOccupiedByBubble) {
			window.draw(bubble->getSprite());
		}
}





