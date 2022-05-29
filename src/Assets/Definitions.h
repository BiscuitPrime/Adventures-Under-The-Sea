#pragma once

#include <utility>

#define spriteSize 64
#define windowWidth 1920
#define windowHeight 1080

class Definitions {
public:
	static std::pair<int, int> orthoToIso(std::pair<int, int> orthoCoords);
};