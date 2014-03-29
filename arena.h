#ifndef ARENA_H_INCLUDED
#define ARENA_H_INCLUDED

#include "fighter.h"

class Arena
{
public:
    Arena() {}
    /**
        Function return codes:
                    TRUE | FALSE
        usePotion : 55 | 20;
        attack : 43 | 10;
        useMagic : 15 | 5;
    **/
    void fight(Fighter* first, Fighter* second)
    {
        while(first->getHealth() > 0 && second->getHealth() > 0)
        {
            /** TODO: catch the case when someone is freezed */
            while(first->fight(second) == 0)
                first->fight(second);

            while(second->fight(first) == 0)
                second->fight(first);
        }
    }
};


#endif // ARENA_H_INCLUDED
