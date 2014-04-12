#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "map.h"
#include "entity.h"
#include "hero.h"
#include "orc.h"

using namespace std;

Map* board = new Map();

string generateRandomString(int length)
{
    string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    string result;
    result.resize(length);

    for(int i = 0; i < length; i++)
        result[i] = charset[rand() % charset.length()];

    return result;
}

int main()
{
    srand(time(NULL));
    Entity* hero = new Hero("Niki", 100, 1, 2);
    Weapon* weap = new Weapon("axe", 20);
    hero->equipWeapon(*weap);

    Entity* enemy = new Orc(generateRandomString(5), 100, 1.2, 1, 1);
    board->addEntity(enemy);

    enemy->move(1, 0, board);
    enemy->move(1, 2, board);

    cout<<board->getEntity(3,3)->getName()<<endl;
    return 0;
}
