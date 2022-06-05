
file(GLOB SOURCES CONFIGURE_DEPENDS *.h *.cpp)

add_library(src ${SOURCES}  "Assets/GameAssets.h" "World/Tile.h" "World/Tile.cpp" "World/Tilemap.h" "World/Tilemap.cpp" "Actors/Actor.h" "Actors/Actor.cpp" "Actors/Player.h" "Actors/Player.cpp" "Actors/Enemy.h" "Actors/Enemy.cpp" "Actors/PlayerCommands/PlayerCommands.h" "Actors/PlayerStates/PlayerState.h" "Actors/PlayerStates/PlayerState.cpp" "Actors/PlayerStates/PlayerStates.h" "Actors/PlayerStates/PlayerStates.cpp" "Actors/PlayerCommands/PlayerCommands.cpp" "Actors/PlayerCommands/InputHandler.h" "Actors/PlayerCommands/InputHandler.cpp" "Actors/Modules/HealthModule.h" "Actors/Modules/HealthModule.cpp" "Actors/Modules/OxygenModule.h" "Actors/Modules/OxygenModule.cpp" "Assets/Definitions.h" "Assets/Definitions.cpp" "Assets/GameAssets.cpp" "GameManager.h" "GameManager.cpp"   "Entities/Bubble.h" "Entities/Entity.h" "Entities/Bubble.cpp" "Actors/Strategy/Strategy.h" "Actors/Strategy/MovementStrategy.h" "Actors/Strategy/AttackStrategy.h"    "Actors/Strategy/ConcreteStrategies/MeleeAttackStrategy.h" "Actors/Strategy/ConcreteStrategies/RangeAttackStrategy.h" "Actors/Strategy/ConcreteStrategies/PursuitStrategy.h" "Actors/Strategy/ConcreteStrategies/FleeStrategy.h" "Actors/Strategy/Context.h" "Actors/Strategy/Context.cpp")

target_include_directories(src PUBLIC ./)

target_link_libraries(src PUBLIC pugixml sfml-graphics)
