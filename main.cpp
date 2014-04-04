#include <iostream>
#include "fighter.h"
#include "Niki.h"
#include "arena.h"
#include "Test.h"

using namespace std;

int main()
{
    Arena* arena = new Arena();
    Fighter* girls = new Girls();
    Fighter* harry = new Harry();
    Fighter* tnt = new TNT();
    Fighter* simon = new Simon();
    Fighter* angel = new Angel();
    Fighter* newFight = new NewFight();

    arena->fight(newFight, angel);
    return 0;
}
