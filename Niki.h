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
//        if(this->getHealth() < 40)
            //usePotion();

        attack(other);
    }
};

class Bron : public Fighter
{
public:
    Bron() : Fighter(Warrior, "Bron")
    {

    }

    virtual void fight(Fighter* other)
    {
        /**
            It always freezes its oponents
        */
        if(!other->isFreezed())
        {
            useMagic(Freeze, other);
        }

        if(other->getHealth() <= 45)
            useMagic(Frenzy, other);

        attack(other);
    }
};

#endif // NIKI_H_INCLUDED
