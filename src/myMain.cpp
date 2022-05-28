#include "myMain.h"
#include <SFML/Graphics.hpp>
#include <Actors/Player.h>
#include <Actors/PlayerCommands/InputHandler.h>

int myMain()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    //---------------------------------
    //Creating the player :
    std::string playerTexturePath = "../../../../resources/Sprites/Player.png";
    auto player = Player(playerTexturePath);
    player.setPosition(sf::Vector2f(0, 0));
    //Creating the input handler associated to the player :
    auto inputHandler = InputHandler();
    //---------------------------------

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        inputHandler.handleInput(&player, &window); //each frame we call the inputhandler's handle input that will analyse the inputted data

        window.clear(sf::Color::Black);
        window.draw(player.getSprite());
        window.display();
    }
    return 0;
}