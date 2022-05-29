#pragma once

#include <utility>

#define spriteSize 64			// size in px for the sprites
#define lines 10				// how many lines of tiles the tilemap has
#define columns 10				// how many columns of tiles the tilemap has 
#define windowWidth 1920		// width of the render window
#define windowHeight 1080		//height of the render window

class Definitions {
public:
	static std::pair<double, double> orthoToIso(std::pair<int, int> orthoCoords);
};