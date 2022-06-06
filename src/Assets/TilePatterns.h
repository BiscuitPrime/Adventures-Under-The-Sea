#pragma once

class TilePattern {
public:
	TilePattern() = default;
	// attack and movement patterns getters
	std::vector<sf::Vector2i> sphere3Getter() const { return sphere3; }
	std::vector<sf::Vector2i> adjacentTilesGetter() const { return adjacentTiles; }
	std::vector<sf::Vector2i> cross3Getter() const { return cross3; }
	// attack and movement patterns
	std::vector<sf::Vector2i> sphere3 = { sf::Vector2i(0,0), sf::Vector2i(1,0), sf::Vector2i(1,1), sf::Vector2i(0,1), sf::Vector2i(-1,1), sf::Vector2i(-1,0), sf::Vector2i(-1,-1), sf::Vector2i(0,-1), sf::Vector2i(1,-1),
												sf::Vector2i(2,0), sf::Vector2i(2,1), sf::Vector2i(1,2), sf::Vector2i(0,2), sf::Vector2i(-1,2), sf::Vector2i(-2,1), sf::Vector2i(-2,0), sf::Vector2i(-2,-1), sf::Vector2i(-1,-2), sf::Vector2i(0,-2), sf::Vector2i(1,-2), sf::Vector2i(2,-1),
												sf::Vector2i(3,0), sf::Vector2i(0,3), sf::Vector2i(-3,0), sf::Vector2i(0,-3) };
	std::vector<sf::Vector2i> adjacentTiles = { sf::Vector2i(1,0), sf::Vector2i(0,1), sf::Vector2i(-1,0), sf::Vector2i(0,-1) };
	std::vector<sf::Vector2i> cross3 = { sf::Vector2i(1,0), sf::Vector2i(0,1), sf::Vector2i(-1,0), sf::Vector2i(0,-1),
												sf::Vector2i(2,0), sf::Vector2i(0,2), sf::Vector2i(-2,0), sf::Vector2i(0,-2),
												sf::Vector2i(3,0), sf::Vector2i(0,3), sf::Vector2i(-3,0), sf::Vector2i(0,-3) };
};