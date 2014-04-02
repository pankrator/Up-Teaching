#include "fighter.h"
#include <iostream>

using namespace std;

void Fighter::create(HeroType className)
{
    this->health = 100;
    this->numOfPotions = 3;
    if(className == Warrior)
    {
        manaPoints = 50;
        damage = 10;
    }
    else
    {
        manaPoints = 100;
        damage = 5;
    }
}

void Fighter::usePotion()
{
    if(turn == false)
        return;
    if(numOfPotions > 0)
    {
        this->turn = false;
        this->health+=30;
        numOfPotions--;
    }
}

void Fighter::attack(Fighter* other)
{
    if(turn == false)
        return;

    this->turn = false;

    if(this->frenzy == true)
    {
        this->damage = 20;
    }
    else
    {
        this->damage = 10;
    }
    other->takeHealth(this->damage);
}

void Fighter::useMagic(MagicType magicType, Fighter* other)
{
    if(turn == false)
        return;

    switch(magicType)
    {
    case Freeze:
        if(manaPoints >= 30)
        {
            other->setFreezed(true);
            manaPoints -= 30;
            turn = false;
        }
        break;
    case Fireball:
        if(this->manaPoints >= 20)
        {
            other->takeHealth(25);
            this->manaPoints -= 20;
            turn = false;
        }
        break;
    case Frenzy:
        if(this->manaPoints >= 25)
        {
            this->frenzy = true;
            this->manaPoints -= 25;
        }
        break;
    }
}

void Fighter::takeHealth(int amount)
{
    this->health -= amount;
}
