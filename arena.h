#ifndef ARENA_H_INCLUDED
#define ARENA_H_INCLUDED

#include "fighter.h"

using namespace std;

class Arena
{
public:
    Arena() {}

    void fight(Fighter* first, Fighter* second)
    {
        while(first->getHealth() > 0 && second->getHealth() > 0)
        {
            if(first->getHealth() <= 0)
            {
                cout<<"Second fighter is the winner!"<<endl;
                return;
            }

            if (!first->isFreezed())
            {
                while(first->getTurn() == true)
                    first->fight(second);
            } else
            {
                cout<<"First is freezed"<<endl;
            }


            if(second->getHealth() <= 0)
            {
                cout<<"First fighter is the winner!"<<endl;
                return;
            }

            if(!second->isFreezed())
            {
                while(second->getTurn() == true)
                    second->fight(first);
            }
            else
            {
                cout<<"Second is freezed"<<endl;
            }

            /** Reset state **/
            first->setFreezed(false);
            first->setTurn(true);

            second->setFreezed(false);
            second->setTurn(true);
        }
    }

};


#endif // ARENA_H_INCLUDED
