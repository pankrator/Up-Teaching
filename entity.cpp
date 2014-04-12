#include "entity.h"
#include "map.h"
#include <string>

using namespace std;

bool Entity::isAlive()
{
    return (this->health > 0);
}

void Entity::takeDamage(float damage)
{
    this->health -= damage;
}

void Entity::takeHealing(int healPoints)
{
    if(!this->isAlive())
        return;

    this->health += healPoints;
}

void Entity::equipWeapon(const Weapon& weap)
{
    this->weapon = weap;
    this->isEquiped = true;
}


bool Entity::move(int x, int y, Map* board)
{
    /** TODO: Make sure the place is free before moving **/
    board->move(this->x + x, this->y + y, this);
    this->x+=x;
    this->y+=y;
    return true;
}


