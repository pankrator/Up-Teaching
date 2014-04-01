#include <iostream>
#include "fighter.h"
#include "Niki.h"
#include "arena.h"

using namespace std;

int main()
{
    Arena* arena = new Arena();
    Fighter* niki = new Niki();
    Fighter* other = new Bron();

    arena->fight(niki, other);
    return 0;
}
