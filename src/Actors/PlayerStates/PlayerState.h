#pragma once
/*
* File used to define the various available Player states
*/


//basic player state class :
class PlayerState {
public:
	PlayerState() {};
	virtual void handleInput();
};

//idle state :
class PlayerIdleState : public PlayerState
{
public:
	PlayerIdleState();
	void handleInput() override;
};

//moving state :
class PlayerMovingState : public PlayerState 
{
public:
	PlayerMovingState() {};
	void handleInput() override;
};

class PlayerAttackState : public PlayerState
{
public:
	PlayerAttackState();
	void handleInput() override;
};

class PlayerMineAttackState : public PlayerAttackState
{
public:
	PlayerMineAttackState();
	void handleInput() override;
};

class PlayerTorpedoAttackState : public PlayerAttackState
{
public:
	PlayerTorpedoAttackState() {};
	void handleInput() override;
};