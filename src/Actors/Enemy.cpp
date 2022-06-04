#include "Enemy.h"
#include "Enemy.h"
#include "Enemy.h"
#include "Enemy.h"
/*
*	Source code of the Enemy class.
*/
#include <Actors/Enemy.h>


Enemy::Enemy(int id,std::string texturePath, Tilemap* tilem) : Actor{ id, texturePath } 
{
	actorType = ENEMY;
	_state = EnemyStates::STATE_IDLE; //by default in idle state
	health.setInitialHealth(1);
	tilemap = tilem;
}


//method called when the enemy is dying.
void Enemy::death() 
{
	std::cout << "Enemy has died.\n";
	_state = STATE_DEAD;
	removeEnemyOnTilemap();
	//exit(500);
}

//method that returns the next state
void Enemy::nextState()
{
	if (_state == STATE_IDLE) { _state = STATE_MOVING; isEnemyLoopFinished = false; }
	else if (_state == STATE_MOVING) { _state = STATE_ATTACK; }
	else if (_state == STATE_ATTACK) { _state = STATE_IDLE; }
}

//method that handles the internal enemy logic :
void Enemy::handleEnemy(sf::RenderWindow* window)
{
	std::cout << "Handling enemy !\n";
	if (_state == STATE_IDLE) {
		nextState();
	}
	if (_state == STATE_MOVING)
	{
		moveEnemyCommand();
	}
	else if (_state == STATE_ATTACK)
	{
		attackEnemyCommand();
	}
}

//method that moves the enemy
void Enemy::moveEnemyCommand()
{
	std::cout << "Enemy performing movement !\n";

	removeEnemyOnTilemap(); //we remove the enemy's reference from the currently occupied tile

	//we physically move the enemy :
	sf::Vector2i newEnemyPos = getCoordinates() + Definitions::getRandomDirection(); //LATER : REMOVE sf::VECTOR2i(1,0) by a call to a function that will determine the direction
	int tries = 0;
	while (testNewPositionValidity(newEnemyPos) == -1 && tries<=5) {
		newEnemyPos = getCoordinates() + Definitions::getRandomDirection();
		tries += 1;
	}
	if (tries == 6) //if a new valid position could not be found, the enemy stays on his position
	{
		newEnemyPos = getCoordinates();
	}
	setOrthoCoordinates(newEnemyPos); //set orthogonal coordinates
	setIsoCoordinates(Definitions::orthoToIsoWithOffset(newEnemyPos)); //set isometric coordinates
	getSprite().setPosition(getIsometricCoordinates()); //set sprite position

	std::cout << "Enemy now on " << getCoordinates().x << " , " << getCoordinates().y;
	setUpEnemyOnTilemap(); //we tell the new occupied tile that it is occupied by an enemy

	nextState();
}

//method that makes the enemy attack
void Enemy::attackEnemyCommand()
{
	std::cout << "Enemy performing attack !\n";
	/* TODO ATTACK */
	nextState();
	isEnemyLoopFinished = true;
}

//method that will spawn the enemy at a given place entered as a parameter
void Enemy::spawn(sf::Vector2i spawnPoint)
{
	setOrthoCoordinates(spawnPoint); //set orthogonal coordinates
	setIsoCoordinates(Definitions::orthoToIsoWithOffset(spawnPoint)); //set isometric coordinates
	getSprite().setPosition(getIsometricCoordinates()); //set sprite position
}

//methods that tell the currently occupied tile that it is, indeed, occupied by the enemy
void Enemy::setUpEnemyOnTilemap()
{
	tilemap->getTile(getCoordinates())->setCurrentActor(this);
	std::cout << "Tile " << tilemap->getTile(getCoordinates())->getOrthogonalCoords().x << " , " << tilemap->getTile(getCoordinates())->getOrthogonalCoords().y << " now contains ref towards " << tilemap->getTile(getCoordinates())->getCurActor()->getId()<<'\n';
	tilemap->getTile(getCoordinates())->setOccupied(true);
}

//methods that tell the currently occupied tile that it is, indeed, inoccupied by the enemy as the enemy is leaving
void Enemy::removeEnemyOnTilemap()
{
	tilemap->getTile(getCoordinates())->setCurrentActor(nullptr);
	tilemap->getTile(getCoordinates())->setOccupied(false);
}

//function that tests if the new position will be valid
int Enemy::testNewPositionValidity(sf::Vector2i pos)
{
	if (pos.x >= 0 && pos.x < lines && pos.y >= 0 && pos.y < columns) //we test if the new position is in bounds with the tilemap
	{
		if (tilemap->getTile(pos)->getAccessibility() && !tilemap->getTile(pos)->getOccupied()) //we test if tile is accessible and inoccupied
		{
			//if it is, we can move the enemy to it
			return 0;
		}
	}
	return -1;
}
