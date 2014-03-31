#ifndef NIKI_H_INCLUDED
#define NIKI_H_INCLUDED

#include "fighter.h"

class Niki : public Fighter
{
public:
    Niki() : Fighter(Warrior)
    {

    }

    virtual void fight(Fighter* other)
    {
        if(this->getHealth() < 40)
            usePotion();

        attack(other);
    }
};

#endif // NIKI_H_INCLUDED
