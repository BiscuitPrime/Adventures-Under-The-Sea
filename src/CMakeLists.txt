
file(GLOB SOURCES CONFIGURE_DEPENDS *.h *.cpp)

add_library(src ${SOURCES}  "Assets/GameAssets.h" "World/Tile.h" "World/Tile.cpp" "World/Tilemap.h" "World/Tilemap.cpp")
target_include_directories(src PUBLIC ./)

target_link_libraries(src PUBLIC pugixml)
