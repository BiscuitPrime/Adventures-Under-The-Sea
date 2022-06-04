#include <gtest/gtest.h>
#include <Actors/Player.h>
#include <Actors/PlayerCommands/InputHandler.h>
#include <Actors/Enemy.h>
#include <GameManager.h>

/*
* File of the various tests of the program
*/
TEST(TestActor, TestLoadingSprite) //test wether or not files are correctly loaded for actors -  ------------------ TO REWRITE -----------------------------
{
    std::string playerTexturePath = "../../../../projet-cpp/resources/Sprites/Player.png";
    auto player = Player(playerTexturePath);
    sf::Texture actorTexture;
    bool actorSpriteLoad = actorTexture.loadFromFile(playerTexturePath);
    EXPECT_EQ(actorSpriteLoad, true); // TEST IS USELESS FOR NOW
}

TEST(TestActor, TestChangingState) //test wether or not the states of the player changes
{
    std::string playerTexturePath = "../../../../projet-cpp/resources/Sprites/Player.png";
    auto player = Player(playerTexturePath);
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    //auto inputHandler = InputHandler();

    sf::Keyboard::isKeyPressed(sf::Keyboard::A); // ???????????????????????????????? -> how do you test a player input ??
    //inputHandler.handleInput(&player, &window);

    //ASSERT_EQ(inputHandler.getState()->getName(), PlayerStates::moving.getName()) << "Player states have not been updated correctly"; //TEST IS USELESS FOR NOW AS WE CAN'T CHANGE INPUT
}

TEST(TestActor, TestHealthPlayer) //test wether or not the player's Health is initialized correctly AND is correctly updated
{
    std::string playerTexturePath = "../../../../projet-cpp/resources/Sprites/Player.png";
    auto player = Player(playerTexturePath);
    ASSERT_EQ(player.getHealth(), 10) << "Player health has not initizalized correctly";
    player.takeDamage(1);
    ASSERT_EQ(player.getHealth(), 9) << "Player health has not taken damage correctly";
}

TEST(TestActor, TestOxygenPlayer) //test wether or not the player's Oxygen is initialized correctly AND is correctly updated
{
    std::string playerTexturePath = "../../../../projet-cpp/resources/Sprites/Player.png";
    auto player = Player(playerTexturePath);
    ASSERT_EQ(player.getOxygen(),20) << "Player oxygen has not initialized correctly";
    player.decreaseOxygen(2);
    ASSERT_EQ(player.getOxygen(), 18) << "Player oxygen has not decreased correctly";
    player.increaseOxygen(1);
    ASSERT_EQ(player.getOxygen(), 19) << "Player oxygen has not increased correctly";
}

TEST(TestActor, TestHealthEnemy) //test wether or not the enemy's Health is initialized correctly AND is correctly updated //TO REWRITE
{
    std::string enemyTexturePath = "../../../../projet-cpp/resources/Sprites/Player.png";
    /*
    auto enemy = Enemy(1, enemyTexturePath);
    ASSERT_EQ(enemy.getHealth(), 10) << "Player health has not initizalized correctly";
    enemy.takeDamage(1);
    ASSERT_EQ(enemy.getHealth(), 9) << "Player health has not taken damage correctly";
    */
}

TEST(TestActor, TestConcurrentHealth) //test if two health pool can coexist without issues //TO REWRITE
{
    std::string enemyTexturePath = "../../../../projet-cpp/resources/Sprites/Player.png";
    /*
    auto enemy = Enemy(1, enemyTexturePath);
    std::string playerTexturePath = "../../../../projet-cpp/resources/Sprites/Player.png";
    auto player = Player(playerTexturePath);
    player.takeDamage(1);
    enemy.takeDamage(2);
    ASSERT_NE(player.getHealth(), enemy.getHealth()) << "Player and enemy health pool seem to be indistinct";
    */
}

TEST(TestActor, TestEnemyStates) //test wether the enemy states are updated //TO REWRITE
{
    std::string enemyTexturePath = "../../../../projet-cpp/resources/Sprites/Player.png";
    /*
    auto enemy = Enemy(1, enemyTexturePath);
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    ASSERT_EQ(enemy.getState(),EnemyStates::STATE_IDLE) << "Enemy did not have its states setup at idle by default";
    enemy.setState(EnemyStates::STATE_MOVING);
    ASSERT_EQ(enemy.getState(), EnemyStates::STATE_MOVING) << "Enemy did not have its state updated";
    */
}

TEST(TestGameLogic, TestAddingEnemy) //test wether or not gameManager's adding enemies function works
{
    GameAssets ga;
    std::string playerTexturePath = "../../../../projet-cpp/resources/Sprites/Player.png";
    auto player = Player(playerTexturePath);
    auto inputHandler = InputHandler(ga);
    std::string enemyTexturePath = "../../../../projet-cpp/resources/Sprites/EldritchSquidRight.png";
    /*
    auto enemy = Enemy(1, enemyTexturePath);
    Tilemap tilemap;
    sf::RenderWindow window(sf::VideoMode(0,0), "SFML window");
    auto gameManager = GameManager(&player, enemy, &inputHandler, &tilemap, &window, &ga);
    auto enemy2 = Enemy(1, enemyTexturePath);
    ASSERT_EQ(gameManager.addEnemy(enemy2), -1)<< "Both enemies have id as 1, GameManager's defense should return -1 -> Did not return -1 here";
    */
}
