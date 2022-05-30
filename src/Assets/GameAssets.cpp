#include "GameAssets.h"

GameAssets::GameAssets() {
    std::string resourceDirectory = "resources/Sprites/";
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

    tileIndexes.insert({ "sand", sandTile });
    tileIndexes.insert({ "sandSelected", sandTileSelected });
    tileIndexes.insert({ "sandTall", sandTallTile });
    tileIndexes.insert({ "sandTallSelected", sandTallTileSelected });
    tileIndexes.insert({ "sandAlgea", sandAlgeaTile });
    tileIndexes.insert({ "sandAlgeaSelected", sandAlgeaTileSelected });
    tileIndexes.insert({ "sandAlgea2", sandAlgea2Tile });
    tileIndexes.insert({ "sandAlgea2Selected", sandAlgea2TileSelected });
    tileIndexes.insert({ "sandAlgeaTall", sandAlgeaTallTile });
    tileIndexes.insert({ "sandAlgeaTallSelected", sandAlgeaTallTileSelected });
    tileIndexes.insert({ "sandAlgeaTall2", sandAlgeaTall2Tile });
    tileIndexes.insert({ "sandAlgeaTall2Selected", sandAlgeaTall2TileSelected });
}