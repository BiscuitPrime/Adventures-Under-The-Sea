#include "GameAssets.h"
/*
* Source code of the game assets
*/


GameAssets::GameAssets() {
    std::string resourceDirectory = "resources/sprites/";

    // UI
    Titlescreen.loadFromFile(resourceDirectory + "titlescreen.png");
    AlertHealth.loadFromFile(resourceDirectory + "AlertHealth.png");
    AlertOxygen.loadFromFile(resourceDirectory + "AlertOxygen.png");
   
    // actors
    Player.loadFromFile(resourceDirectory + "player.png");
    EldritchSquidRight.loadFromFile(resourceDirectory + "EldritchSquidRight.png");
    EldritchSquidLeft.loadFromFile(resourceDirectory + "EldritchSquidLeft.png");
    WyrmRight.loadFromFile(resourceDirectory + "WyrmRight.png");
    WyrmLeft.loadFromFile(resourceDirectory + "WyrmLeft.png");

    // entities
    Bubble.loadFromFile(resourceDirectory + "bubble.png");

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

    tileIndexes.try_emplace("sand", sandTile);
    tileIndexes.try_emplace("sanda", sandTileAttack);
    tileIndexes.try_emplace("sandm", sandTileMovement);
    tileIndexes.try_emplace("sands", sandTileSelected);
    tileIndexes.try_emplace("sandas", sandTileAttackSelected);
    tileIndexes.try_emplace("sandms", sandTileMovementSelected);
    tileIndexes.try_emplace("sandTall", sandTallTile);
    tileIndexes.try_emplace("sandTalla", sandTallTileAttack);
    tileIndexes.try_emplace("sandTallm", sandTallTileMovement);
    tileIndexes.try_emplace("sandTalls", sandTallTileSelected);
    tileIndexes.try_emplace( "sandTallas", sandTallTileAttackSelected );
    tileIndexes.try_emplace( "sandTallms", sandTallTileMovementSelected );
    tileIndexes.try_emplace( "sandAlgea", sandAlgeaTile );
    tileIndexes.try_emplace( "sandAlgeaa", sandAlgeaTileAttack );
    tileIndexes.try_emplace( "sandAlgeam", sandAlgeaTileMovement );
    tileIndexes.try_emplace( "sandAlgeas", sandAlgeaTileSelected );
    tileIndexes.try_emplace( "sandAlgeaas", sandAlgeaTileAttackSelected );
    tileIndexes.try_emplace( "sandAlgeams", sandAlgeaTileMovementSelected );
    tileIndexes.try_emplace( "sandAlgea2", sandAlgea2Tile );
    tileIndexes.try_emplace( "sandAlgea2a", sandAlgea2TileAttack );
    tileIndexes.try_emplace( "sandAlgea2m", sandAlgea2TileMovement );
    tileIndexes.try_emplace( "sandAlgea2s", sandAlgea2TileSelected );
    tileIndexes.try_emplace( "sandAlgea2as", sandAlgea2TileAttackSelected );
    tileIndexes.try_emplace( "sandAlgea2ms", sandAlgea2TileMovementSelected );
    tileIndexes.try_emplace( "sandAlgeaTall", sandAlgeaTallTile );
    tileIndexes.try_emplace( "sandAlgeaTalla", sandAlgeaTallTileAttack );
    tileIndexes.try_emplace( "sandAlgeaTallm", sandAlgeaTallTileMovement );
    tileIndexes.try_emplace( "sandAlgeaTalls", sandAlgeaTallTileSelected );
    tileIndexes.try_emplace( "sandAlgeaTallas", sandAlgeaTallTileAttackSelected );
    tileIndexes.try_emplace( "sandAlgeaTallms", sandAlgeaTallTileMovementSelected );
    tileIndexes.try_emplace("sandAlgeaTall2", sandAlgeaTall2Tile);
    tileIndexes.try_emplace("sandAlgeaTall2a", sandAlgeaTall2TileAttack);
    tileIndexes.try_emplace("sandAlgeaTall2m", sandAlgeaTall2TileMovement);
    tileIndexes.try_emplace("sandAlgeaTall2s", sandAlgeaTall2TileSelected);
    tileIndexes.try_emplace("sandAlgeaTall2as", sandAlgeaTall2TileAttackSelected);
    tileIndexes.try_emplace("sandAlgeaTall2ms", sandAlgeaTall2TileMovementSelected);

    tileIndexes.try_emplace("sandRock", sandRockTile);
    tileIndexes.try_emplace("sandRocka", sandRockTileAttack);
    tileIndexes.try_emplace("sandRockm", sandRockTileMovement);
    tileIndexes.try_emplace("sandRocks", sandRockTileSelected);
    tileIndexes.try_emplace("sandRockas", sandRockTileAttackSelected);
    tileIndexes.try_emplace("sandRockms", sandRockTileMovementSelected);
    tileIndexes.try_emplace("sandRockAlgea", sandRockAlgeaTile);
    tileIndexes.try_emplace("sandRockAlgeaa", sandRockAlgeaTileAttack);
    tileIndexes.try_emplace("sandRockAlgeam", sandRockAlgeaTileMovement);
    tileIndexes.try_emplace("sandRockAlgeas", sandRockAlgeaTileSelected);
    tileIndexes.try_emplace("sandRockAlgeaas", sandRockAlgeaTileAttackSelected);
    tileIndexes.try_emplace("sandRockAlgeams", sandRockAlgeaTileMovementSelected);
    tileIndexes.try_emplace("sandRock2", sandRock2Tile);
    tileIndexes.try_emplace("sandRock2a", sandRock2TileAttack);
    tileIndexes.try_emplace("sandRock2m", sandRock2TileMovement);
    tileIndexes.try_emplace("sandRock2s", sandRock2TileSelected);
    tileIndexes.try_emplace("sandRock2as", sandRock2TileAttackSelected);
    tileIndexes.try_emplace("sandRock2ms", sandRock2TileMovementSelected);
    tileIndexes.try_emplace("sandRock2Algea", sandRock2AlgeaTile); 
    tileIndexes.try_emplace("sandRock2Algeam", sandRock2AlgeaTileMovement);
    tileIndexes.try_emplace("sandRock2Algeas", sandRock2AlgeaTileSelected);
    tileIndexes.try_emplace("sandRock2Algeaa", sandRock2AlgeaTileAttack);
    tileIndexes.try_emplace("sandRock2Algeaas", sandRock2AlgeaTileAttackSelected);
    tileIndexes.try_emplace("sandRock2Algeams", sandRock2AlgeaTileMovementSelected);
    tileIndexes.try_emplace("sandRock3", sandRock3Tile);
    tileIndexes.try_emplace("sandRock3a", sandRock3TileAttack);
    tileIndexes.try_emplace("sandRock3m", sandRock3TileMovement);
    tileIndexes.try_emplace("sandRock3s", sandRock3TileSelected);
    tileIndexes.try_emplace("sandRock3as", sandRock3TileAttackSelected);
    tileIndexes.try_emplace("sandRock3ms", sandRock3TileMovementSelected);
    tileIndexes.try_emplace("sandRock3Algea", sandRock3AlgeaTile);
    tileIndexes.try_emplace("sandRock3Algeaa", sandRock3AlgeaTileAttack);
    tileIndexes.try_emplace("sandRock3Algeam", sandRock3AlgeaTileMovement);
    tileIndexes.try_emplace("sandRock3Algeas", sandRock3AlgeaTileSelected);
    tileIndexes.try_emplace("sandRock3Algeaas", sandRock3AlgeaTileAttackSelected);
    tileIndexes.try_emplace("sandRock3Algeams", sandRock3AlgeaTileMovementSelected);
}