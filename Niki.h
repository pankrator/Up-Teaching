#ifndef NIKI_H_INCLUDED
#define NIKI_H_INCLUDED

#include "fighter.h"

using namespace std;

class Niki : public Fighter
{
public:
    Niki() : Fighter(Warrior, "Niki")
    {

    }

    virtual void fight(Fighter* other)
    {
        if(this->getHealth() < 40)
            usePotion();

        useMagic(Frenzy, other);

        attack(other);
    }
};

class Bron : public Fighter
{
public:
    Bron() : Fighter(Magician, "Bron")
    {

    }

    virtual void fight(Fighter* other)
    {
        if(!other->isFreezed())
        {
            useMagic(Freeze, other);
        }
        if(this->getHealth() <= 30)
            usePotion();

        //if(other->getHealth() < 25)
        useMagic(Fireball, other);

        useMagic(Frenzy, other);

        attack(other);
    }
};

#endif // NIKI_H_INCLUDED
