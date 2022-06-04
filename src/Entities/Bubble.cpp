#include "Bubble.h"

Bubble::Bubble(sf::Vector2i ortho, sf::Vector2f iso, GameAssets const& ga)
{
	orthoCoords = ortho;
	isoCoords = iso;
	entityTexture = ga.Bubble;
	sf::Sprite sprite;
	sprite.setTexture(entityTexture);
	sprite.setPosition(iso);
	entitySprite = sprite;
}
