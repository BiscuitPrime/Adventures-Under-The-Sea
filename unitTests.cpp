#include <gtest/gtest.h>
#include <Actors/Player.h>
#include <Actors/PlayerCommands/InputHandler.h>
#include <Actors/Enemy.h>
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
    auto inputHandler = InputHandler();

    sf::Keyboard::isKeyPressed(sf::Keyboard::A); // ???????????????????????????????? -> how do you test a player input ??
    inputHandler.handleInput(&player, &window);

    ASSERT_EQ(inputHandler.getState()->getName(), PlayerStates::moving.getName()) << "Player states have not been updated correctly"; //TEST IS USELESS FOR NOW AS WE CAN'T CHANGE INPUT
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

TEST(TestActor, TestHealthEnemy) //test wether or not the enemy's Health is initialized correctly AND is correctly updated
{
    std::string enemyTexturePath = "../../../../projet-cpp/resources/Sprites/Player.png";
    auto enemy = Enemy(enemyTexturePath);
    ASSERT_EQ(enemy.getHealth(), 10) << "Player health has not initizalized correctly";
    enemy.takeDamage(1);
    ASSERT_EQ(enemy.getHealth(), 9) << "Player health has not taken damage correctly";
}
