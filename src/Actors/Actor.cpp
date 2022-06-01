#include "Actor.h"
#include "Actor.h"
#include "Actor.h"
/*
* We define the code of the Actor class here :
*/
#include "Actor.h";
#include <iostream>

//Constructor of the actor class
Actor::Actor(std::string texturePath) {
    //we allocate the appropriate sprite for the approcpriate actor :
    bool actorSpriteLoad = actorTexture.loadFromFile(texturePath);
    if (!actorSpriteLoad)
    {
        std::cout << "Error on img load for actor\n";
        exit(0);
    }
    actorSprite.setTexture(actorTexture);

    //we define its health module :
    health = HealthModule();
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

//method that returns the health of an actor
int Actor::getHealth()
{
    return health.getHealth();
}

//method that updates the actor's health module
void Actor::takeDamage(int dmg)
{
    int curHp=health.takeDamage(dmg);
    if (curHp <= 0) //if the actor's life pool has reached 0, it dies : the death() function is dependant to the considered actor
    {
        death(); 
    }
}
 //method that handles the actor's death
void Actor::death()
{
    std::cout << "Actor has died\n";
}

//method that returns the actor's type :
ActorType Actor::getType()
{
    return actorType;
}
