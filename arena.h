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
                cout<<second->getName()<<" is the winner! He is with "<<second->getHealth()<<" health"<<endl;
                return;
            }

            if(!first->isFreezed())
            {
                while(first->getTurn() == true)
                {
                    first->fight(second);
                }
            }

            first->setTurn(true);
            first->setFreezed(false);

            if(second->getHealth() <= 0)
            {
                cout<<first->getName()<<" is the winner! He is with "<<first->getHealth()<<" health"<<endl;
                return;
            }

            if(!second->isFreezed())
            {
                while(second->getTurn() == true)
                {
                    second->fight(first);
                }
            }

            //cout<<first->getHealth()<<" "<<second->getHealth()<<endl;

            /** Reset state **/

            second->setTurn(true);
            second->setFreezed(false);

        }

        if(first->getHealth() <= 0)
        {
            cout<<second->getName()<<" is the winner! He is with "<<second->getHealth()<<" health"<<endl;
            return;
        }

        if(second->getHealth() <= 0)
        {
            cout<<first->getName()<<" is the winner! He is with "<<first->getHealth()<<" health"<<endl;
            return;
        }
    }

};


#endif // ARENA_H_INCLUDED
