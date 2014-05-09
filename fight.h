#ifndef FIGHT_H_INCLUDED
#define FIGHT_H_INCLUDED
#include "entity.h"
#include <math.h>

class Battle
{
public:

    void simulate(Entity& one, Entity& two)
    {
        if(!isNear(one, two))
        {
            return;
        }

        if(!one.isAlive() || !two.isAlive())
        {
            cout<<"CHAO CHAO"<<endl;
            return;
        }

        while (true)
        {
            getInput(one, two);
            if (closeBattle(two))
            {
                break;
            }
            int power = two.attack();
            one.takeDamage(power);
            if (closeBattle(one))
            {
                break;
            }
        }
    }

private:
    bool isNear(Entity& one, Entity& two)
    {
        return (abs(one.getX() - two.getX()) < 2 &&
           abs(one.getY() - two.getY()) < 2);
    }
    bool closeBattle(Entity& ent)
    {
        if(!ent.isAlive())
        {
            cout<<ent.getName()<<" "<<"is dead meat!"<<endl;
        }
        return !ent.isAlive();
    }

    void getInput(Entity& attacker, Entity& other)
    {
        int n;
        cout<<"1.Attack()"<<endl<<"2.Take healing"<<endl;
        cin>>n;

        switch(n)
        {
        case 1:
            other.takeDamage(attacker.attack());
            break;
        case 2:
            attacker.takeHealing(20);
            break;
        }
    }


};

#endif // FIGHT_H_INCLUDED
