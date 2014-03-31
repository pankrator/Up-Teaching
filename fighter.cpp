#include "fighter.h"

void Fighter::create(HeroType className)
{
    this->health = 100;
    this->numOfPotions = 3;
    if(className == Warrior)
    {
        manaPoints = 50;
        damage = 30;
    }
    else
    {
        manaPoints = 100;
        damage = 15;
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
    other->takeHealth(this->damage);
}

void Fighter::useMagic(MagicType magicType, Fighter* other)
{
    if(turn == false)
        return;

    switch(magicType)
    {
    case Freeze:
        other->freezed = true;
        break;
    case Fireball:
        other->takeHealth(45);
        break;
    case Frenzy:
        this->damage+=15;
        break;
    }
}

void Fighter::takeHealth(int amount)
{
    this->health -= amount;
}
