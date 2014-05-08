#include "hero.h"
#include "orc.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

class Fight
{
public:
    Hero hero;
    Orc orc;
    int turn;

    Fight() {}

    Fight(Hero hero, Orc orc)
    {
        srand((unsigned)time(0));
        int randomN = (rand()%100) + 1;
        if(randomN <= 50)
            turn = 0;
        else
            turn = 1;

        this->hero = hero;
        this->orc = orc;
    }

    void simulateFight()
    {
        if(!hero.isAlive() || !orc.isAlive())
        {
            cout<<"Ne moje da se izpalni simulaciqta"<<endl;
            return;
        }

        while(1)
        {
            if(turn == 0)
            {
                cout<<hero.getName()<<" takes turn"<<endl;
                if(!orc.isAlive())
                {
                    cout<<hero.getName()<<" is winner!"<<endl;
                    break;
                }
                cout<<hero.getName()<<" is attacking "<<orc.getName()<<" with ";
                cout<<hero.getWeapon().getType()<<endl;
                cout<<" and dealth "<<hero.attack()<<" damage"<<endl;
                orc.takeDamage(hero.attack());
                turn = 1;
            }
            else if(turn == 1)
            {
                cout<<orc.getName()<<" takes turn"<<endl;
                if(!hero.isAlive())
                {
                    cout<<orc.getName()<<" is winner!"<<endl;
                    break;
                }
                cout<<orc.getName()<<" is attacking "<<orc.getName()<<" with ";
                cout<<orc.getWeapon().getType()<<endl;
                cout<<" and dealth "<<orc.attack()<<" damage"<<endl;
                hero.takeDamage(orc.attack());
                turn = 0;
            }
        }
    }
};
