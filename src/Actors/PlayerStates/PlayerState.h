#pragma once
#include <string>
#include <Actors/PlayerCommands/PlayerCommands.h>
/*
* Header used to define the various available Player states
*/

//basic player state class :
class PlayerState {
private:
	std::string stateName;
protected:
	MoveCommand moveCommand;
	MineAttackCommand mineCommand;
	TorpedoAttackCommand torpedoCommand;
public:
	PlayerState();
	virtual void stateExecute(Player* player, sf::RenderWindow* window, Tilemap* tilemap);
	std::string getName() const { return stateName; };
};

//idle state :
class PlayerIdleState : public PlayerState
{
private:
	std::string stateName;
public:
	PlayerIdleState();
	void stateExecute(Player* player, sf::RenderWindow* window, Tilemap* tilemap) override;
};

//moving state :
class PlayerMovingState : public PlayerState
{
private:
	std::string stateName;
public:
	PlayerMovingState();
	void stateExecute(Player* player, sf::RenderWindow* window, Tilemap* tilemap) override;
};

//attack state :
class PlayerAttackState : public PlayerState
{
private:
	std::string stateName;
public:
	PlayerAttackState();
	void stateExecute(Player* player, sf::RenderWindow* window, Tilemap* tilemap) override;
};

//mine attack state :
class PlayerMineAttackState : public PlayerAttackState
{
private:
	std::string stateName;
public:
	PlayerMineAttackState();
	void stateExecute(Player* player, sf::RenderWindow* window, Tilemap* tilemap) override;
};

//torpedo attack state :
class PlayerTorpedoAttackState : public PlayerAttackState
{
private:
	std::string stateName;
public:
	PlayerTorpedoAttackState();
	void stateExecute(Player* player, sf::RenderWindow* window, Tilemap* tilemap) override;
};

