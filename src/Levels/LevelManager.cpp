#include "LevelManager.h"
/*
*	Source code for the LevelManager class
*/

//constructor :
LevelManager::LevelManager()
{}

//we get the next level in the list of levels contained by LevelManager
int LevelManager::changeLevel()
{
	//_currentLevel = &levels.at(static_cast<std::vector<GameManager, std::allocator<GameManager>>::size_type>(_currentLevel->getId()) + 1);
    return 0;
}

//returns the currently active level :
GameManager* LevelManager::getCurrentLevel()
{
	return _currentLevel;
}
