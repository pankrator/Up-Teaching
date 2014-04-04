#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include "fighter.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

class Harry : public Fighter
{
public:
    Harry() : Fighter(Magician, "Potter") {}

    virtual void fight(Fighter* other)
    {
        int mana=180;
        useMagic(Fireball, other);
        mana-=30;
        if(mana>30)
        {
            useMagic(Freeze, other);
            mana-=30;
            useMagic(Fireball, other);
            mana-=20;
            if(this->getHealth()<=70)
            {
                usePotion();
            }
        }
        else
        {
            useMagic(Fireball, other);
        }

        attack(other);
    }
};

class TNT : public Fighter
{
public:
    TNT() : Fighter(Magician, "Durvenica") {}
    virtual void fight(Fighter* other)
    {
        if(this->getHealth()<70)
            usePotion();

        useMagic(Fireball, other);
        attack(other);
    }
};


class Simon : public Fighter
{
public:

    Simon():Fighter(Magician, "Aneylune") {}
    virtual void fight(Fighter* other)
    {
        if(this->getHealth() < 70)
        {
            usePotion();
        }
        useMagic(Fireball, other);

        attack(other);



    }
};

class NewFight : public Fighter
{
public:
    NewFight() : Fighter(Magician, "Harry") {}
    virtual void fight(Fighter* other)
    {
        int count = 0;
        if(other->getHealth() > 69)
            useMagic(Fireball, other);

        else if(other->getHealth() > 39 && other->getHealth() < 70)
        {
            if(this->getHealth() < 40 && this->getHealth() > 0 && count < 4)
            {
                this->usePotion();
                count++;
            }
        }

        else if(this->getHealth() < 40 && this->getHealth() > 0)
        {
                this->usePotion();
                if(this->getHealth() < 40 && this->getHealth() > 0 && count < 4)
            {
                this->usePotion();
                count++;
            }
        }

        else if(other->getHealth() < 40)
        {
                useMagic(Fireball, other);
                if(this->getHealth() < 40 && this->getHealth() > 0 && count < 4)
                {
                    this->usePotion();
                    count++;
                }
        }
        else if(other->getHealth() < 20)
        {
                useMagic(Fireball, other);
                if(this->getHealth() < 40 && this->getHealth() > 0 && count < 4)
                {
                    this->usePotion();
                    count++;
                }
        }
    }
};


class Girls: public Fighter
{
public:
    Girls() : Fighter(Magician,"Voldemort") {}
    virtual void fight(Fighter* other)
    {
        int n;
        if (this->getHealth() < 40)
        {
            usePotion();
        }
        if (this->getHealth() < 65)
        {
            useMagic(Fireball, other);
        }
        if(this->getHealth() > 65)
        {
            n = rand()*1;
            if (n == 0)
            {
                useMagic(Freeze, other);
            }
            else
            {
                useMagic(Fireball, other);
            }

        }

        attack(other);


    }

};


class Angel : public Fighter
{
public:
    Angel() : Fighter(Magician, "Angel") {}
    virtual void fight(Fighter* other)
    {
        if(this -> getHealth() < 30)usePotion();
        useMagic(Freeze, other);
        useMagic(Fireball, other);
        useMagic(Fireball, other);
        attack(other);
    }
};


#endif // TEST_H_INCLUDED
