
file(GLOB SOURCES CONFIGURE_DEPENDS *.h *.cpp)

<<<<<<< HEAD
add_library(src ${SOURCES}   "World/Tile.h")
=======
add_library(src ${SOURCES}   "Actors/Actor.h" "Actors/Actor.cpp" "Actors/Player.cpp" "Actors/player.h" "Actors/Enemy.h" "Actors/PlayerStates/PlayerState.h" "Actors/PlayerStates/PlayerState.cpp" "Actors/PlayerStates/PlayerStates.h" "Actors/PlayerStates/PlayerStates.cpp" "Actors/PlayerCommands/PlayerCommands.h")
>>>>>>> henriactors
target_include_directories(src PUBLIC ./)

target_link_libraries(src PUBLIC pugixml sfml-graphics)
