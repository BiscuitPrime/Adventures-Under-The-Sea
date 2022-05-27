#include "Actors/PlayerStates/PlayerStates.h"

PlayerIdleState PlayerStates::idle = PlayerIdleState();
PlayerMovingState PlayerStates::moving = PlayerMovingState();
PlayerAttackState PlayerStates::attack = PlayerAttackState();
PlayerMineAttackState PlayerStates::mine = PlayerMineAttackState();
PlayerTorpedoAttackState PlayerStates::torpedo = PlayerTorpedoAttackState();