#include <gtest/gtest.h>
#include <Actors/Player.h>
/*
* File of the various tests of the program
*/


TEST(TestActor, TestSprite) //test wether or not files are correctly loaded for actors
{
    std::string playerTexturePath = "../../../../projet-cpp/resources/Sprites/Player.png";
    auto player = Player(playerTexturePath);
    sf::Texture actorTexture;
    bool actorSpriteLoad = actorTexture.loadFromFile(playerTexturePath);
    EXPECT_EQ(actorSpriteLoad, true);
}
