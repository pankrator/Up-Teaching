#ifndef NIKI_H_INCLUDED
#define NIKI_H_INCLUDED

#include "fighter.h"

class Niki : public Fighter
{
public:
    Niki() : Fighter(Warrior)
    {

    }

    virtual int fight(Fighter* other)
    {
        if(this->getHealth() < 40)
            return usePotion();

        return attack(other);
    }
};

#endif // NIKI_H_INCLUDED
