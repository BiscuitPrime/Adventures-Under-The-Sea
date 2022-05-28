/*
* We define the code of the Actor class here :
*/
#include "Actor.h";
#include <iostream>

//Constructor of the actor class
Actor::Actor(std::string texturePath) {
	bool actorSpriteLoad = actorTexture.loadFromFile(texturePath);
    if (!actorSpriteLoad)
    {
        std::cout << "Error on img load for actor\n";
        exit(0);
    }
    actorSprite.setTexture(actorTexture);
}

//method that returns the sprite
sf::Sprite Actor::getSprite()
{
    return actorSprite;
}

//method that returns the actor's position
sf::Vector2f Actor::getPosition()
{
    return actorPosition;
}

//method that changes the actor's position 
void Actor::setPosition(sf::Vector2f position)
{
    actorPosition = position; //we change the actor object's position
    actorSprite.setPosition(position); //we also update the sprite
}
