#include <gtest/gtest.h>
#include <Actors/Player.h>
#include <Actors/PlayerCommands/PlayerHandler.h>
#include <Actors/Enemy.h>
#include <UI/UI.h>
#include <GameManager.h>

/*
* File of the various tests of the program
*/

// --------------------------------------------------------------- TEST ACTORS -------------------------------------------------------------------------------
TEST(TestActor, TestChangingState) //test wether or not the states of the player changes
{
    sf::Texture texture;
    auto player = Player(0,texture);
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    GameAssets ga;
    auto ui = UI(texture,texture);
    auto inputHandler = PlayerHandler(ga,&ui);
    ASSERT_EQ(inputHandler.getState()->getName(), PlayerStates::idle.getName()) << "Player states have not been initialized correctly";
}

TEST(TestActor, TestEnemyStates) //test wether the enemy states are updated //TO REWRITE
{
    sf::Texture texture;
    Tilemap tilemap;
    auto enemy = Enemy(1, texture, &tilemap);
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    ASSERT_EQ(enemy.getState(),EnemyStates::STATE_IDLE) << "Enemy did not have its states setup at idle by default";
    enemy.setState(EnemyStates::STATE_MOVING);
    ASSERT_EQ(enemy.getState(), EnemyStates::STATE_MOVING) << "Enemy did not have its state updated";
}

// --------------------------------------------------------------- TEST MODULES -------------------------------------------------------------------------------

TEST(TestModules, TestHealthPlayer) //test wether or not the player's Health is initialized correctly AND is correctly updated
{
    sf::Texture playerTexture;
    auto player = Player(0,playerTexture);
    ASSERT_EQ(player.getHealth(), HEALTH_INITIAL_PLAYER) << "Player health has not initizalized correctly";
    player.takeDamage(1);
    ASSERT_EQ(player.getHealth(), HEALTH_INITIAL_PLAYER-1) << "Player health has not taken damage correctly";
}

TEST(TestModules, TestOxygenPlayer) //test wether or not the player's Oxygen is initialized correctly AND is correctly updated
{
    sf::Texture playerTexture;
    auto player = Player(0,playerTexture);
    ASSERT_EQ(player.getOxygen(),OXYGEN_INITIAL_PLAYER) << "Player oxygen has not initialized correctly";
    player.decreaseOxygen(2);
    ASSERT_EQ(player.getOxygen(), OXYGEN_INITIAL_PLAYER-2) << "Player oxygen has not decreased correctly";
    player.increaseOxygen(1);
    ASSERT_EQ(player.getOxygen(), OXYGEN_INITIAL_PLAYER-1) << "Player oxygen has not increased correctly";
    player.increaseOxygen(10);
    ASSERT_EQ(player.getOxygen(), 5) << "Player oxygen is not maxed";
    player.decreaseOxygen(10);
    ASSERT_EQ(player.getOxygen(), 0) << "Player oxygen is not floored";
}

TEST(TestModules, TestHealthEnemy) //test wether or not the enemy's Health is initialized correctly AND is correctly updated
{
    Tilemap tilemap;
    sf::Texture texture;
    auto enemy = Enemy(1, texture, &tilemap);
    ASSERT_EQ(enemy.getHealth(), HEALTH_INITIAL_ENEMY_BASE) << "Enemy health has not initizalized correctly";
    enemy.takeDamage(1);
    ASSERT_EQ(enemy.getHealth(), HEALTH_INITIAL_ENEMY_BASE-1) << "Enemy health has not taken damage correctly";
}

// --------------------------------------------------------------- TEST GAMELOGIC -------------------------------------------------------------------------------

TEST(TestGameLogic, TestAddingEnemy) //test wether or not gameManager's adding enemies function works
{
    GameAssets ga;
    Tilemap tilemap;
    sf::Texture enemyTexture = ga.EldritchSquidLeft;
    auto enemy = Enemy(1, enemyTexture, &tilemap);
    auto gameManager = GameManager(1,nullptr, enemy, nullptr, &tilemap, nullptr, &ga);
    auto enemy2 = Enemy(1, enemyTexture, &tilemap);
    ASSERT_EQ(gameManager.addEnemy(enemy2), -1)<< "Both enemies have id as 1, GameManager's defense should return -1 -> Did not return -1 here";
}

// --------------------------------------------------------------- TEST TILEMAP -------------------------------------------------------------------------------
TEST(TestTilemap, TestBuildTilemap) {
    Tilemap tilemap;
    GameAssets ga;
    auto* fileName = (char*)"../../../../projet-cpp/resources/tilemaps/TilemapForTesting.xml";
    int rt = tilemap.buildTilemap(fileName, ga); // mettre dans le test
    ASSERT_EQ(rt, 0) << "Method not properly executed";
    ASSERT_EQ(tilemap.getLabel(), "level1") << "Label not properly parsed";

    // test on tile 0, 0 of the tilemap
    sf::Vector2i orthoCoords = sf::Vector2i(0, 0);
    sf::Vector2f isoCoords = Definitions::orthoToIsoWithOffset(orthoCoords);
    Tile* tile = tilemap.getTile(orthoCoords);
    ASSERT_EQ(tile->getOrthogonalCoords().x, orthoCoords.x) << "Orthogonal coords of tile (0, 0) not properly set";
    ASSERT_EQ(tile->getOrthogonalCoords().y, orthoCoords.y) << "Orthogonal coords of tile (0, 0) not properly set";
    ASSERT_EQ(tile->getIsometricCoords().x, isoCoords.x) << "Isometric coords of tile (0, 0) not properly set";
    ASSERT_EQ(tile->getIsometricCoords().y, isoCoords.y) << "Isometric coords of tile (0, 0) not properly set";
    ASSERT_EQ(tile->getStringTexture(), "sandTall") << "Texture as stirng of tile (0, 0) not properly set";
    ASSERT_EQ(tile->getAccessibility(), false) << "Accessibility of tile (0, 0) not properly set";
    ASSERT_EQ(tile->getAvailable(), false) << "Availability of tile (0, 0) not properly set";
    ASSERT_EQ(tile->hasBubble(), false) << "Bubble wrongly set on tile (0, 0)";
    ASSERT_EQ(tile->getOccupied(), false) << "Tile (0, 0) wrongly occupied";
}

TEST(TestTilemap, TestSetTile) 
{
    Tilemap tilemap;
    GameAssets ga;
    auto* fileName = (char*)"../../../../projet-cpp/resources/tilemaps/TilemapForTesting.xml";
    tilemap.buildTilemap(fileName, ga); // mettre dans le test
    sf::Vector2i orthoCoords = sf::Vector2i(0, 0);
    sf::Vector2f isoCoords = Definitions::orthoToIsoWithOffset(orthoCoords);
    tilemap.setTile(0, 0, isoCoords.x, isoCoords.y, "sand", true, ga);
    Tile* tile = tilemap.getTile(orthoCoords);
    ASSERT_EQ(tile->getOrthogonalCoords().x, orthoCoords.x) << "Orthogonal coords of tile (0, 0) not properly set";
    ASSERT_EQ(tile->getOrthogonalCoords().y, orthoCoords.y) << "Orthogonal coords of tile (0, 0) not properly set";
    ASSERT_EQ(tile->getIsometricCoords().x, isoCoords.x) << "Isometric coords of tile (0, 0) not properly set";
    ASSERT_EQ(tile->getIsometricCoords().y, isoCoords.y) << "Isometric coords of tile (0, 0) not properly set";
    ASSERT_EQ(tile->getStringTexture(), "sand") << "Texture as stirng of tile (0, 0) not properly set";
    ASSERT_EQ(tile->getAccessibility(), true) << "Accessibility of tile (0, 0) not properly set";
}

// --------------------------------------------------------------- TEST DEFINITIONS -------------------------------------------------------------------------------

TEST(TestDefinition, TestOrthoToIso) 
{
    auto orthoCoords = sf::Vector2i(5, 5);
    auto isoCoords = Definitions::orthoToIso(orthoCoords);
    ASSERT_EQ(isoCoords.x, 0) << "X coordinate is wrong";
    ASSERT_EQ(isoCoords.y, 160) << "Y coordinate is wrong";
}


TEST(TestDefinition, TestIsoToOrtho) 
{
    auto isoCoords = sf::Vector2i(0, 160);
    auto orthoCoords = Definitions::isoToOrtho(isoCoords);
    ASSERT_EQ(orthoCoords.x, 5) << "X coordinate is wrong (should be 5): " << orthoCoords.x;
    ASSERT_EQ(orthoCoords.y, 5) << "Y coordinate is wrong (should be 5): " << orthoCoords.y;
}

TEST(TestDefinition, TestManhattanDistance) 
{
    auto distance = Definitions::manhattanDistance(sf::Vector2i(0, 0), sf::Vector2(10, 5));
    ASSERT_EQ(distance, 15) << "Distance false";
    distance = Definitions::manhattanDistance(sf::Vector2i(0, 0), sf::Vector2(0, 0));
    ASSERT_EQ(distance, 0) << "Distance false";
    distance = Definitions::manhattanDistance(sf::Vector2i(0, 0), sf::Vector2(-10, 0));
    ASSERT_EQ(distance, 10) << "Distance false";

}