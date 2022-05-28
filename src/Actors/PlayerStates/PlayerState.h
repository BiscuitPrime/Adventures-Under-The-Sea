#pragma once
/*
* Header used to define the various available Player states
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
	PlayerMovingState();
	void handleStateInput() override;
};
/*
//attack state :
class PlayerAttackState : public PlayerState
{
public:
	PlayerAttackState();
	void handleStateInput() override;
};

//mine attack state :
class PlayerMineAttackState : public PlayerAttackState
{
public:
	PlayerMineAttackState();
	void handleStateInput() override;
};

//torpedo attack state :
class PlayerTorpedoAttackState : public PlayerAttackState
{
public:
	PlayerTorpedoAttackState();
	void handleStateInput() override;
};
*/
