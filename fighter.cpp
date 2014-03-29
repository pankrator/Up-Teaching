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

int Fighter::usePotion()
{
    if(numOfPotions > 0)
    {
        this->health+=30;
        numOfPotions--;
        return 1;
    }

    return 0;
}

int Fighter::attack(Fighter* other)
{
    other->takeHealth(this->damage);

    return 1;
}

int Fighter::useMagic(MagicType magicType, Fighter* other)
{
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

    return 1;
}

void Fighter::takeHealth(int amount)
{
    this->health -= amount;
}
