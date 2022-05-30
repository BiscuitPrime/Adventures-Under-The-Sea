#pragma once
#include <string>
/*
* Header used to define the various available Player states
*/

//basic player state class :
class PlayerState {
private:
	std::string stateName;
public:
	PlayerState();
	virtual void stateExecute();
	virtual std::string getName();
};

//idle state :
class PlayerIdleState : public PlayerState
{
private:
	std::string stateName;
public:
	PlayerIdleState();
	void stateExecute() override;
	std::string getName() override;
};

//moving state :
class PlayerMovingState : public PlayerState
{
private:
	std::string stateName;
public:
	PlayerMovingState();
	void stateExecute() override;
	std::string getName() override;
};

//attack state :
class PlayerAttackState : public PlayerState
{
private:
	std::string stateName;
public:
	PlayerAttackState();
	void stateExecute() override;
	std::string getName() override;
};

//mine attack state :
class PlayerMineAttackState : public PlayerAttackState
{
private:
	std::string stateName;
public:
	PlayerMineAttackState();
	void stateExecute() override;
	std::string getName() override;
};

//torpedo attack state :
class PlayerTorpedoAttackState : public PlayerAttackState
{
private:
	std::string stateName;
public:
	PlayerTorpedoAttackState();
	void stateExecute() override;
	std::string getName() override;
};

