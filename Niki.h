#ifndef NIKI_H_INCLUDED
#define NIKI_H_INCLUDED

#include "fighter.h"

using namespace std;

class Niki : public Fighter
{
public:
    Niki() : Fighter(Warrior)
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
    Bron() : Fighter(Warrior)
    {

    }

    virtual void fight(Fighter* other)
    {
        if(this->getHealth() < 20)
            usePotion();

        if(!other->isFreezed())
        {
            useMagic(Freeze, other);
            cout<<"Freeze"<<endl;
        }

        if(other->getHealth() <= 45)
            useMagic(Frenzy, other);

        cout<<"Attack"<<endl;
        attack(other);
    }
};

#endif // NIKI_H_INCLUDED
