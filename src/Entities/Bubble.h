#pragma once

#include <Entities/Entity.h>

class Bubble : public Entity {
public:
	Bubble(sf::Vector2i ortho, sf::Vector2f iso, GameAssets const& ga);
};
