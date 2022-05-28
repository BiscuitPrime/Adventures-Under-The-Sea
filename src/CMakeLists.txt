
file(GLOB SOURCES CONFIGURE_DEPENDS *.h *.cpp)

add_library(src ${SOURCES}  "Assets/GameAssets.h" "World/Tile.h" "World/Tile.cpp" "World/Tilemap.h" "World/Tilemap.cpp" "Actors/Actor.h" "Actors/Actor.cpp" "Actors/Player.h" "Actors/Player.cpp" "Actors/Enemy.h" "Actors/Enemy.cpp" "Actors/PlayerCommands/PlayerCommands.h" "Actors/PlayerStates/PlayerState.h" "Actors/PlayerStates/PlayerState.cpp" "Actors/PlayerStates/PlayerStates.h" "Actors/PlayerStates/PlayerStates.cpp" "Actors/PlayerCommands/PlayerCommands.cpp" "Actors/PlayerCommands/InputHandler.h" "Actors/PlayerCommands/InputHandler.cpp")

target_include_directories(src PUBLIC ./)

target_link_libraries(src PUBLIC pugixml sfml-graphics)
