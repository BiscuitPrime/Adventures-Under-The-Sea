/*
* We define the code of the Actor class here :
*/
#include "Actor.h"
#include <iostream>

//Constructor of the actor class
Actor::Actor(int nid, sf::Texture texture) : actorTexture{ texture }, id{ nid }, actorType{ENEMY}, health{ HealthModule() }
{
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

