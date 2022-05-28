#pragma once
/*
* Header used to define the various available Player states
*/

//basic player state class :
class PlayerState {
public:
	PlayerState();
	virtual void stateExecute();
};

//idle state :
class PlayerIdleState : public PlayerState
{
public:
	PlayerIdleState();
	void stateExecute() override;
};

//moving state :
class PlayerMovingState : public PlayerState
{
public:
	PlayerMovingState();
	void stateExecute() override;
};

//attack state :
class PlayerAttackState : public PlayerState
{
public:
	PlayerAttackState();
	void stateExecute() override;
};

//mine attack state :
class PlayerMineAttackState : public PlayerAttackState
{
public:
	PlayerMineAttackState();
	void stateExecute() override;
};

//torpedo attack state :
class PlayerTorpedoAttackState : public PlayerAttackState
{
public:
	PlayerTorpedoAttackState();
	void stateExecute() override;
};

