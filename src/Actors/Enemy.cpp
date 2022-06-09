#include "Enemy.h"
#include <Actors/Strategy/ConcreteStrategies/FleeStrategy.h>
#include <Actors/Strategy/ConcreteStrategies/RangeAttackStrategy.h>
#include <Actors/Strategy/ConcreteStrategies/PursuitStrategy.h>
#include <Actors/Strategy/ConcreteStrategies/MeleeAttackStrategy.h>


Enemy::Enemy(int id, sf::Texture texture, Tilemap* tilem) : Actor{ id, texture }, tilemap{ tilem }
{
	actorType = ENEMY;
	_state = EnemyStates::STATE_IDLE; //by default in idle state
	health.setInitialValue(HEALTH_INITIAL_ENEMY_BASE);
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
void Enemy::handleEnemy(Player* player)
{
	std::cout << "Handling enemy !\n";
	if (_state == STATE_IDLE) {
		nextState();
	}
	if (_state == STATE_MOVING)
	{
		setStrategies(player->getCoordinates());
		auto movement = movementStrategy->execute(getCoordinates(), player->getCoordinates(), tilemap, movementRange);
		moveEnemyCommand(movement);
	}
	else if (_state == STATE_ATTACK)
	{
		int damage = attackStrategy->execute(getCoordinates(), player->getCoordinates());
		attackEnemyCommand(damage, player);
	}
}

//method that moves the enemy
void Enemy::moveEnemyCommand(sf::Vector2i movement)
{
	std::cout << "Enemy performing movement !\n";

	removeEnemyOnTilemap(); //we remove the enemy's reference from the currently occupied tile

	//we physically move the enemy :
	sf::Vector2i newEnemyPos = movement;
	setOrthoCoordinates(newEnemyPos); //set orthogonal coordinates
	setIsoCoordinates(Definitions::orthoToIsoWithOffset(newEnemyPos)); //set isometric coordinates
	getSprite().setPosition(getIsometricCoordinates()); //set sprite position

	std::cout << "Enemy now on " << getCoordinates().x << " , " << getCoordinates().y;
	setUpEnemyOnTilemap(); //we tell the new occupied tile that it is occupied by an enemy

	nextState();
}

//method that makes the enemy attack
void Enemy::attackEnemyCommand(int damage, Player* player)
{
	std::cout << "Enemy performing attack ! Deal " << damage << " hp\n";

	player->takeDamage(damage);
	nextState();
	isEnemyLoopFinished = true;
}

void Enemy::setStrategies(sf::Vector2i playerPos)
{
	if (Definitions::manhattanDistance(playerPos, getCoordinates()) > fleeRange) {
		// set flee behavior
		auto static mstrategy = FleeStrategy();
		movementStrategy = &mstrategy;
		auto static astrategy = RangeAttackStrategy();
		attackStrategy = &astrategy;
	}
	else {
		auto static mstrategy = PursuitStrategy();
		movementStrategy = &mstrategy;
		auto static astrategy = MeleeAttackStrategy();
		attackStrategy = &astrategy;
	}
}

//method that will spawn the enemy at a given place entered as a parameter
void Enemy::spawn(sf::Vector2i spawnPoint)
{
	setOrthoCoordinates(spawnPoint); //set orthogonal coordinates
	setIsoCoordinates(Definitions::orthoToIsoWithOffset(spawnPoint)); //set isometric coordinates
	sf::Vector2f spritePosition = sf::Vector2f(getIsometricCoordinates().x, getIsometricCoordinates().y + ACTOR_SPRITE_VERTICAL_OFFSET);
	getSprite().setPosition(spritePosition); //set sprite position
	setUpEnemyOnTilemap(); //we tell the new occupied tile that it is occupied by an enemy
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
	if (pos.x >= 0 && pos.x < LINES && pos.y >= 0 && pos.y < COLUMNS) //we test if the new position is in bounds with the tilemap
	{
		if (tilemap->getTile(pos)->getAccessibility() && !tilemap->getTile(pos)->getOccupied()) //we test if tile is accessible and inoccupied
		{
			//if it is, we can move the enemy to it
			return 0;
		}
	}
	return -1;
}
