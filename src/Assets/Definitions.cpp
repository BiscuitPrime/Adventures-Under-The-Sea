#include "Definitions.h"

std::pair<double, double> Definitions::orthoToIso(std::pair<int, int> orthoCoords)
{
	std::pair<int, int> coordinates = { spriteSize * orthoCoords.first, spriteSize * orthoCoords.second };
	std::pair<double, double> isoCoords = { (coordinates.first - coordinates.second) * 0.5, (coordinates.first + coordinates.second) * 0.25 };
	return isoCoords;
}