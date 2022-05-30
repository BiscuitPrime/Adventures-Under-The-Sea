#include "Definitions.h"
#include <iostream> //REMOVE IT ONCE DONE

std::pair<double, double> Definitions::orthoToIso(std::pair<int, int> orthoCoords)
{
	std::pair<int, int> coordinates = { spriteSize * orthoCoords.first, spriteSize * orthoCoords.second };
	std::pair<double, double> isoCoords = { (coordinates.first - coordinates.second) * 0.5, (coordinates.first + coordinates.second) * 0.25 };
	return isoCoords;
}

std::pair<double, double> Definitions::isoToOrtho(std::pair<int, int> isoCoords) 
{
	std::pair<double, double> orthoCoords = { (isoCoords.first + (2 * isoCoords.second)), ((2 * isoCoords.second) - isoCoords.first) };
	orthoCoords = { orthoCoords.first / 64, orthoCoords.second / 64};
	return orthoCoords;
}