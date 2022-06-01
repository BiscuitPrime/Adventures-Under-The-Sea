#include "GameAssets.h"

GameAssets::GameAssets() {
    std::string resourceDirectory = "resources/sprites/";
   
    // level 1 tiles (sand & algea)
    sandTile.loadFromFile(resourceDirectory + "sand.png");
    sandTallTile.loadFromFile(resourceDirectory + "sandTall.png");
    sandAlgeaTile.loadFromFile(resourceDirectory + "sandAlgea.png");
    sandAlgea2Tile.loadFromFile(resourceDirectory + "sandAlgea2.png");
    sandAlgeaTallTile.loadFromFile(resourceDirectory + "sandAlgeaTall.png");
    sandAlgeaTall2Tile.loadFromFile(resourceDirectory + "sandAlgeaTall2.png");
    // selected variant
    sandTileSelected.loadFromFile(resourceDirectory + "sands.png");
    sandTallTileSelected.loadFromFile(resourceDirectory + "sandTalls.png");
    sandAlgeaTileSelected.loadFromFile(resourceDirectory + "sandAlgeas.png");
    sandAlgea2TileSelected.loadFromFile(resourceDirectory + "sandAlgea2s.png");
    sandAlgeaTallTileSelected.loadFromFile(resourceDirectory + "sandAlgeaTalls.png");
    sandAlgeaTall2TileSelected.loadFromFile(resourceDirectory + "sandAlgeaTall2s.png");
    // attack variant 
    sandTileAttack.loadFromFile(resourceDirectory + "sanda.png");
    sandTallTileAttack.loadFromFile(resourceDirectory + "sandTalla.png");
    sandAlgeaTileAttack.loadFromFile(resourceDirectory + "sandAlgeaa.png");
    sandAlgea2TileAttack.loadFromFile(resourceDirectory + "sandAlgea2a.png");
    sandAlgeaTallTileAttack.loadFromFile(resourceDirectory + "sandAlgeaTalla.png");
    sandAlgeaTall2TileAttack.loadFromFile(resourceDirectory + "sandAlgeaTall2a.png");
    // attack and selected variant
    sandTileAttackSelected.loadFromFile(resourceDirectory + "sandas.png");
    sandTallTileAttackSelected.loadFromFile(resourceDirectory + "sandTallas.png");
    sandAlgeaTileAttackSelected.loadFromFile(resourceDirectory + "sandAlgeaas.png");
    sandAlgea2TileAttackSelected.loadFromFile(resourceDirectory + "sandAlgea2as.png");
    sandAlgeaTallTileAttackSelected.loadFromFile(resourceDirectory + "sandAlgeaTallas.png");
    sandAlgeaTall2TileAttackSelected.loadFromFile(resourceDirectory + "sandAlgeaTall2as.png");
    // movement indicator variants
    sandTileMovement.loadFromFile(resourceDirectory + "sandm.png");
    sandTallTileMovement.loadFromFile(resourceDirectory + "sandTallm.png");
    sandAlgeaTileMovement.loadFromFile(resourceDirectory + "sandAlgeam.png");
    sandAlgea2TileMovement.loadFromFile(resourceDirectory + "sandAlgea2m.png");
    sandAlgeaTallTileMovement.loadFromFile(resourceDirectory + "sandAlgeaTallm.png");
    sandAlgeaTall2TileMovement.loadFromFile(resourceDirectory + "sandAlgeaTall2m.png");
    // movement and selected variant
    sandTileMovementSelected.loadFromFile(resourceDirectory + "sandms.png");
    sandTallTileMovementSelected.loadFromFile(resourceDirectory + "sandTallms.png");
    sandAlgeaTileMovementSelected.loadFromFile(resourceDirectory + "sandAlgeams.png");
    sandAlgea2TileMovementSelected.loadFromFile(resourceDirectory + "sandAlgea2ms.png");
    sandAlgeaTallTileMovementSelected.loadFromFile(resourceDirectory + "sandAlgeaTallms.png");
    sandAlgeaTall2TileMovementSelected.loadFromFile(resourceDirectory + "sandAlgeaTall2ms.png");
    //------------------------------------------------------------------------------------------

    // level 3 tiles (sand & rocks)
    sandRockTile.loadFromFile(resourceDirectory + "sandRock.png");
    sandRockAlgeaTile.loadFromFile(resourceDirectory + "sandRockAlgea.png");
    sandRock2Tile.loadFromFile(resourceDirectory + "sandRock2.png");
    sandRock2AlgeaTile.loadFromFile(resourceDirectory + "sandRockAlgea2.png");
    sandRock3Tile.loadFromFile(resourceDirectory + "sandRock3.png");
    sandRock3AlgeaTile.loadFromFile(resourceDirectory + "sandRockAlgea3.png");
    // movement indicator variant
    sandRockTileMovement.loadFromFile(resourceDirectory + "sandRockm.png");
    sandRockAlgeaTileMovement.loadFromFile(resourceDirectory + "sandRockAlgeam.png");
    sandRock2TileMovement.loadFromFile(resourceDirectory + "sandRock2m.png");
    sandRock2AlgeaTileMovement.loadFromFile(resourceDirectory + "sandRockAlgea2m.png");
    sandRock3TileMovement.loadFromFile(resourceDirectory + "sandRock3m.png");
    sandRock3AlgeaTileMovement.loadFromFile(resourceDirectory + "sandRockAlgea3m.png");
    // selected variant
    sandRockTileSelected.loadFromFile(resourceDirectory + "sandRocks.png");
    sandRockAlgeaTileSelected.loadFromFile(resourceDirectory + "sandRockAlgeas.png");
    sandRock2TileSelected.loadFromFile(resourceDirectory + "sandRock2s.png");
    sandRock2AlgeaTileSelected.loadFromFile(resourceDirectory + "sandRockAlgea2s.png");
    sandRock3TileSelected.loadFromFile(resourceDirectory + "sandRock3s.png");
    sandRock3AlgeaTileSelected.loadFromFile(resourceDirectory + "sandRockAlgea3s.png");
    // attack variant
    sandRockTileAttack.loadFromFile(resourceDirectory + "sandRocka.png");
    sandRockAlgeaTileAttack.loadFromFile(resourceDirectory + "sandRockAlgeaa.png");
    sandRock2TileAttack.loadFromFile(resourceDirectory + "sandRock2a.png");
    sandRock2AlgeaTileAttack.loadFromFile(resourceDirectory + "sandRockAlgea2a.png");
    sandRock3TileAttack.loadFromFile(resourceDirectory + "sandRock3a.png");
    sandRock3AlgeaTileAttack.loadFromFile(resourceDirectory + "sandRockAlgea3a.png");
    // attack and selected variant
    sandRockTileAttackSelected.loadFromFile(resourceDirectory + "sandRockas.png");
    sandRockAlgeaTileAttackSelected.loadFromFile(resourceDirectory + "sandRockAlgeaas.png");
    sandRock2TileAttackSelected.loadFromFile(resourceDirectory + "sandRock2as.png");
    sandRock2AlgeaTileAttackSelected.loadFromFile(resourceDirectory + "sandRockAlgea2as.png");
    sandRock3TileAttackSelected.loadFromFile(resourceDirectory + "sandRock3as.png");
    sandRock3AlgeaTileAttackSelected.loadFromFile(resourceDirectory + "sandRockAlgea3as.png");
    // movement and selected variant
    sandRockTileMovementSelected.loadFromFile(resourceDirectory + "sandRockms.png");
    sandRockAlgeaTileMovementSelected.loadFromFile(resourceDirectory + "sandRockAlgeams.png");
    sandRock2TileMovementSelected.loadFromFile(resourceDirectory + "sandRock2ms.png");
    sandRock2AlgeaTileMovementSelected.loadFromFile(resourceDirectory + "sandRockAlgea2ms.png");
    sandRock3TileMovementSelected.loadFromFile(resourceDirectory + "sandRock3ms.png");
    sandRock3AlgeaTileMovementSelected.loadFromFile(resourceDirectory + "sandRockAlgea3ms.png");
    

    tileIndexes.insert({ "sand", sandTile });
    tileIndexes.insert({ "sandm", sandTileMovement });
    tileIndexes.insert({ "sands", sandTileSelected });
    tileIndexes.insert({ "sandms", sandTileMovementSelected });
    tileIndexes.insert({ "sandTall", sandTallTile });
    tileIndexes.insert({ "sandTallm", sandTallTileMovement });
    tileIndexes.insert({ "sandTalls", sandTallTileSelected });
    tileIndexes.insert({ "sandTallms", sandTallTileMovementSelected });
    tileIndexes.insert({ "sandAlgea", sandAlgeaTile });
    tileIndexes.insert({ "sandAlgeam", sandAlgeaTileMovement });
    tileIndexes.insert({ "sandAlgeas", sandAlgeaTileSelected });
    tileIndexes.insert({ "sandAlgeams", sandAlgeaTileMovementSelected });
    tileIndexes.insert({ "sandAlgea2", sandAlgea2Tile });
    tileIndexes.insert({ "sandAlgea2m", sandAlgea2TileMovement });
    tileIndexes.insert({ "sandAlgea2s", sandAlgea2TileSelected });
    tileIndexes.insert({ "sandAlgea2ms", sandAlgea2TileMovementSelected });
    tileIndexes.insert({ "sandAlgeaTall", sandAlgeaTallTile });
    tileIndexes.insert({ "sandAlgeaTallm", sandAlgeaTallTileMovement });
    tileIndexes.insert({ "sandAlgeaTalls", sandAlgeaTallTileSelected });
    tileIndexes.insert({ "sandAlgeaTallms", sandAlgeaTallTileMovementSelected });
    tileIndexes.insert({ "sandAlgeaTall2", sandAlgeaTall2Tile });
    tileIndexes.insert({ "sandAlgeaTall2m", sandAlgeaTall2TileMovement });
    tileIndexes.insert({ "sandAlgeaTall2s", sandAlgeaTall2TileSelected });
    tileIndexes.insert({ "sandAlgeaTall2ms", sandAlgeaTall2TileMovementSelected });

    tileIndexes.insert({ "sandRock", sandRockTile });
    tileIndexes.insert({ "sandRockm", sandRockTileMovement });
    tileIndexes.insert({ "sandRocks", sandRockTileSelected });
    tileIndexes.insert({ "sandRockms", sandRockTileMovementSelected });
    tileIndexes.insert({ "sandRockAlgea", sandRockAlgeaTile });
    tileIndexes.insert({ "sandRockAlgeam", sandRockAlgeaTileMovement });
    tileIndexes.insert({ "sandRockAlgeas", sandRockAlgeaTileSelected });
    tileIndexes.insert({ "sandRockAlgeams", sandRockAlgeaTileMovementSelected });
    tileIndexes.insert({ "sandRock2", sandRock2Tile });
    tileIndexes.insert({ "sandRock2m", sandRock2TileMovement });
    tileIndexes.insert({ "sandRock2s", sandRock2TileSelected });
    tileIndexes.insert({ "sandRock2ms", sandRock2TileMovementSelected });
    tileIndexes.insert({ "sandRock2Algea", sandRock2AlgeaTile }); 
    tileIndexes.insert({ "sandRock2Algeam", sandRock2AlgeaTileMovement });
    tileIndexes.insert({ "sandRock2Algeas", sandRock2AlgeaTileSelected });
    tileIndexes.insert({ "sandRock2Algeams", sandRock2AlgeaTileMovementSelected });
    tileIndexes.insert({ "sandRock3", sandRock3Tile });
    tileIndexes.insert({ "sandRock3m", sandRock3TileMovement });
    tileIndexes.insert({ "sandRock3s", sandRock3TileSelected });
    tileIndexes.insert({ "sandRock3ms", sandRock3TileMovementSelected });
    tileIndexes.insert({ "sandRock3Algea", sandRock3AlgeaTile });
    tileIndexes.insert({ "sandRock3Algeam", sandRock3AlgeaTileMovement });
    tileIndexes.insert({ "sandRock3Algeas", sandRock3AlgeaTileSelected });
    tileIndexes.insert({ "sandRock3Algeams", sandRock3AlgeaTileMovementSelected });
}