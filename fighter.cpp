#include "fighter.h"
#include <iostream>

using namespace std;

void Fighter::create(HeroType className)
{
    this->health = 100;
    this->numOfPotions = 3;
    if(className == Warrior)
    {
        manaPoints = 75;
        damage = 10;
    }
    else
    {
        manaPoints = 180;
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
        cout<<this->name<<" used a health potion"<<endl;
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
    cout<<this->name<<" attacked his opponent"<<endl;
}

void Fighter::useMagic(MagicType magicType, Fighter* other)
{
    if(turn == false)
        return;

    switch(magicType)
    {
    case Freeze:
        if(type != Magician) { return; }
        if(used == Freeze)
        {
            used = Frenzy;
            return;
        }
        if(manaPoints >= 30)
        {
            other->setFreezed(true);
            manaPoints -= 30;
            turn = false;
            used = Freeze;
            cout<<this->name<<" freezed his opponent"<<endl;
        }
        break;
    case Fireball:
        if(type != Magician) { return; }
        if(this->manaPoints >= 20)
        {
            other->takeHealth(25);
            this->manaPoints -= 20;
            turn = false;
            cout<<this->name<<" used fireball"<<endl;
        }
        break;
    case Frenzy:
        if(type != Warrior) { return; }
        if(this->manaPoints >= 25)
        {
            this->frenzy = true;
            this->manaPoints -= 25;
            cout<<this->name<<" used frenzy"<<endl;
        }
        break;
    }
}

void Fighter::takeHealth(int amount)
{
    this->health -= amount;
}
