#pragma once
/*
*	Header containing the definition of the various Command classes implemented via the Command Game Programming Pattern
*/
#include <Actors/Player.h>

//basic PlayerCommand class :
class PlayerCommand {
public:
	PlayerCommand() {};
	virtual void execute(Player* player, sf::RenderWindow* window);
};

//the move command given to the player :
class MoveCommand :public PlayerCommand {
public:
	MoveCommand() {};
	void execute(Player* player, sf::RenderWindow* window) override;
};

//the attack command given to the player :
class MineAttackCommand :public PlayerCommand {
public:
	MineAttackCommand() {};
	void execute(Player* player, sf::RenderWindow* window) override;
};

class TorpedoAttackCommand : public PlayerCommand {
public:
	TorpedoAttackCommand() {};
	void execute(Player* player, sf::RenderWindow* window) override;
};