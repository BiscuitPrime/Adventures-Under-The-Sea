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

#include <iostream>
#include <filesystem>
#include <direct.h>

#include <tmxlite/Map.hpp>
#include <tmxlite/Layer.hpp>
#include <tmxlite/TileLayer.hpp>
#include <tmxlite/ObjectGroup.hpp>
#include <Assets/GameAssets.h>
#include <SFML/Graphics.hpp>


int myMain()
{
    int lines = 5;
    int columns = 5;
    int width = 1920;
    int height = 1080;
    

    sf::RenderWindow window(sf::VideoMode(width, height), "SFML window");
    for (int x = 0; x < columns; x++) {
        for (int y = 0; y < lines; y++) {
            sf::Sprite sprite;
            if (x % 2 == 0) {
                sprite.setTexture(GameAssets::get()->sandTile);
            }
            else {
                sprite.setTexture(GameAssets::get()->sandAlgeaTile);
            }
            sprite.setOrigin(sprite.getPosition().x - GameAssets::get()->sandTile.getSize().x / 2, sprite.getPosition().y - GameAssets::get()->sandTile.getSize().y / 2);
            std::pair<int, int> coords = { 64 * x, 64 * y };
            std::pair<int, int> isoCoords = { (coords.first - coords.second) * 0.5, (coords.first + coords.second) * 0.25};
            std::pair<int, int> offset = { width / 2, height / 2 };
            sprite.setPosition(isoCoords.first + offset.first, isoCoords.second + offset.second);
            
            window.draw(sprite);
        }
    }
    window.display();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    
    /*
    tmx::Map map;
    if (map.load("path/to.tmx"))
    {
        const auto& layers = map.getLayers();
        for (const auto& layer : layers)
        {
            if (layer->getType() == tmx::Layer::Type::Object)
            {
                const auto& objectLayer = layer->getLayerAs<tmx::ObjectGroup>();
                const auto& objects = objectLayer.getObjects();
                for (const auto& object : objects)
                {
                    //do stuff with object properties
                }
            }
            else if (layer->getType() == tmx::Layer::Type::Tile)
            {
                const auto& tileLayer = layer->getLayerAs<tmx::TileLayer>();
                //read out tile layer properties etc...
            }
        }

        const auto& tilesets = map.getTilesets();
        for (const auto& tileset : tilesets)
        {

            //read out tile set properties, load textures etc...
        }
    }*/

    return 0;
}
