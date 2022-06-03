#include "Bubble.h"

Bubble::Bubble(sf::Vector2i ortho, sf::Vector2f iso, GameAssets const& ga)
{
	orthoCoords = ortho;
	isoCoords = iso;
	entityTexture = ga.Bubble;
	entitySprite.setTexture(entityTexture);
	entitySprite.setPosition(iso);
}
