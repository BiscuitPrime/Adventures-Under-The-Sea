#include "GameAssets.h"

GameAssets::GameAssets() {
    std::string resourceDirectory = "resources/sprites/";
   
    // level 1 tiles (sand & algea)
    sandTile.loadFromFile(resourceDirectory + "sand.png");
    sandTileSelected.loadFromFile(resourceDirectory + "sands.png");
    sandTallTile.loadFromFile(resourceDirectory + "sandTall.png");
    sandTallTileSelected.loadFromFile(resourceDirectory + "sandTalls.png");
    sandAlgeaTile.loadFromFile(resourceDirectory + "sandAlgea.png");
    sandAlgeaTileSelected.loadFromFile(resourceDirectory + "sandAlgeas.png");
    sandAlgea2Tile.loadFromFile(resourceDirectory + "sandAlgea2.png");
    sandAlgea2TileSelected.loadFromFile(resourceDirectory + "sandAlgea2s.png");
    sandAlgeaTallTile.loadFromFile(resourceDirectory + "sandAlgeaTall.png");
    sandAlgeaTallTileSelected.loadFromFile(resourceDirectory + "sandAlgeaTalls.png");
    sandAlgeaTall2Tile.loadFromFile(resourceDirectory + "sandAlgeaTall2.png");
    sandAlgeaTall2TileSelected.loadFromFile(resourceDirectory + "sandAlgeaTall2s.png");

    // level 3 tiles (sand & rocks)
    sandRockTile.loadFromFile(resourceDirectory + "sandRock.png");
    sandRockTileSelected.loadFromFile(resourceDirectory + "sandRocks.png");
    sandRockAlgeaTile.loadFromFile(resourceDirectory + "sandRockAlgea.png");
    sandRockAlgeaTileSelected.loadFromFile(resourceDirectory + "sandRockAlgeas.png");
    sandRock2Tile.loadFromFile(resourceDirectory + "sandRock2.png");
    sandRock2TileSelected.loadFromFile(resourceDirectory + "sandRock2s.png");
    sandRock2AlgeaTile.loadFromFile(resourceDirectory + "sandRockAlgea2.png");
    sandRock2AlgeaTileSelected.loadFromFile(resourceDirectory + "sandRockAlgea2s.png");
    sandRock3Tile.loadFromFile(resourceDirectory + "sandRock3.png");
    sandRock3TileSelected.loadFromFile(resourceDirectory + "sandRock3s.png");
    sandRock3AlgeaTile.loadFromFile(resourceDirectory + "sandRockAlgea3.png");
    sandRock3AlgeaTileSelected.loadFromFile(resourceDirectory + "sandRockAlgea3s.png");

    tileIndexes.insert({ "sand", sandTile });
    tileIndexes.insert({ "sands", sandTileSelected });
    tileIndexes.insert({ "sandTall", sandTallTile });
    tileIndexes.insert({ "sandTalls", sandTallTileSelected });
    tileIndexes.insert({ "sandAlgea", sandAlgeaTile });
    tileIndexes.insert({ "sandAlgeas", sandAlgeaTileSelected });
    tileIndexes.insert({ "sandAlgea2", sandAlgea2Tile });
    tileIndexes.insert({ "sandAlgea2s", sandAlgea2TileSelected });
    tileIndexes.insert({ "sandAlgeaTall", sandAlgeaTallTile });
    tileIndexes.insert({ "sandAlgeaTalls", sandAlgeaTallTileSelected });
    tileIndexes.insert({ "sandAlgeaTall2", sandAlgeaTall2Tile });
    tileIndexes.insert({ "sandAlgeaTall2s", sandAlgeaTall2TileSelected });

    tileIndexes.insert({ "sandRock", sandRockTile });
    tileIndexes.insert({ "sandRocks", sandRockTileSelected });
    tileIndexes.insert({ "sandRockAlgea", sandRockAlgeaTile });
    tileIndexes.insert({ "sandRockAlgeas", sandRockAlgeaTileSelected });
    tileIndexes.insert({ "sandRock2", sandRock2Tile });
    tileIndexes.insert({ "sandRock2s", sandRock2TileSelected });
    tileIndexes.insert({ "sandRock2Algea", sandRock2AlgeaTile }); 
    tileIndexes.insert({ "sandRock2Algeas", sandRock2AlgeaTileSelected });
    tileIndexes.insert({ "sandRock3", sandRock3Tile });
    tileIndexes.insert({ "sandRock3s", sandRock3TileSelected });
    tileIndexes.insert({ "sandRock3Algea", sandRock3AlgeaTile });
    tileIndexes.insert({ "sandRock3Algeas", sandRock3AlgeaTileSelected });
}