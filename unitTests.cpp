#include <gtest/gtest.h>
#include "src/World/Tilemap.h"

TEST(TestFindNearestTile, Test1) {
    Tilemap tilemap;
    auto* fileName = (char*)"Tilemap.xml"; // mettre dans le test
    tilemap.buildTilemap(fileName); // mettre dans le test
    Tile& foundTile = tilemap.findNearestTileISO(0, 0);
    Tile& waitedTile = tilemap.getTile(9, 9);
    EXPECT_EQ(foundTile.getIsometricCoords(), waitedTile.getIsometricCoords());

}

