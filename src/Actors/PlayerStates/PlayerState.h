#pragma once
/*
* File used to define the various available Player states
*/


//basic player state class :
class PlayerState {
public:
	PlayerState();
	virtual void handleStateInput();
};

//idle state :
class PlayerIdleState : public PlayerState
{
public:
	PlayerIdleState();
	void handleStateInput() override;
};

//moving state :
class PlayerMovingState : public PlayerState 
{
public:
	PlayerMovingState() {};
	void handleStateInput() override;
};

class PlayerAttackState : public PlayerState
{
public:
	PlayerAttackState() {};
	void handleStateInput() override;
};

class PlayerMineAttackState : public PlayerAttackState
{
public:
	PlayerMineAttackState() {};
	void handleStateInput() override;
};

class PlayerTorpedoAttackState : public PlayerAttackState
{
public:
	PlayerTorpedoAttackState() {};
	void handleStateInput() override;
};
