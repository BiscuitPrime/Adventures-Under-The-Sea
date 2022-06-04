#include "Actor.h"
#include "Actor.h"
#include "Actor.h"
/*
* We define the code of the Actor class here :
*/
#include "Actor.h";
#include <iostream>

//Constructor of the actor class
Actor::Actor(int nid, std::string texturePath) {
    id = nid;
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

