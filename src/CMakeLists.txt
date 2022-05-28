
file(GLOB SOURCES CONFIGURE_DEPENDS *.h *.cpp)

add_library(src ${SOURCES}  "Actors/Actor.h" "Actors/Actor.cpp" "Actors/Player.h" "Actors/Player.cpp" "Actors/Enemy.h" "Actors/Enemy.cpp")
target_include_directories(src PUBLIC ./)

target_link_libraries(src PUBLIC pugixml)
