/* Adaptation of https://github.com/fallahn/tmxlite/blob/master/SFMLExample/src/main.cpp :
    - #include "SFMLOrthogonalLayer.hpp"
      becomes
      #include "SFMLOrthogonalLayer.h"
    - int main()
      becomes
      int myMain()
    - map.load("assets/demo.tmx");
      becomes
      map.load("resources/demo.tmx");
*/
/*********************************************************************
(c) Matt Marchant & contributors 2016 - 2019
http://trederia.blogspot.com
tmxlite - Zlib license.
This software is provided 'as-is', without any express or
implied warranty. In no event will the authors be held
liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute
it freely, subject to the following restrictions:
1. The origin of this software must not be misrepresented;
you must not claim that you wrote the original software.
If you use this software in a product, an acknowledgment
in the product documentation would be appreciated but
is not required.
2. Altered source versions must be plainly marked as such,
and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any
source distribution.
*********************************************************************/

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <tmxlite/Map.hpp>
#include "Actors/Player.h"

int myMain()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    tmx::Map map;
    map.load("resources/Test4.tmx");

    //---------------------------------
    //Creating the player :
    std::string playerTexturePath="../../../../resources/Sprites/Player.png";
    auto player = Player(playerTexturePath);
    player.setPosition(sf::Vector2f(0, 0));
    //---------------------------------

    sf::Clock globalClock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //when mouse clicked
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
        {
            sf::Vector2i pixelMousePos = sf::Mouse::getPosition(window); //get the current mouse position in the window
            sf::Vector2f worldMousePos = window.mapPixelToCoords(pixelMousePos);
            player.setPosition(worldMousePos); //we move the player's position
        }
        window.clear(sf::Color::Black);
        window.draw(player.getSprite());
        window.display();
    }

    return 0;
}
