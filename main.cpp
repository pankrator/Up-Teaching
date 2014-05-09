#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "map.h"
#include "entity.h"
#include "hero.h"
#include "orc.h"
#include "fight.h"

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
//    srand(time(NULL));
//    Entity* hero = new Hero("Niki", 100, 1, 2);
//    Weapon* weap = new Weapon("axe", 20);
//    hero->equipWeapon(*weap);
//
//    Entity* enemy = new Orc(generateRandomString(5), 100, 1.2, 1, 1);
//    board->addEntity(enemy);
//
//    enemy->move(1, 0, board);
//    enemy->move(1, 2, board);
//
//    cout<<board->getEntity(3,3)->getName()<<endl;
    Battle battle = Battle();

    Weapon weap = Weapon("sword", 15);
    Hero hero("ASD", 100, 2, 2);
    hero.equipWeapon(weap);
    Orc orc("ORC", 100, 1.2, 1, 0);
    orc.equipWeapon(weap);

    board->addEntity(&hero);
    board->addEntity(&orc);
    board->printMap();

    hero.move(0, -1, board);

    battle.simulate(hero, orc);

    cout<<endl;
    board->printMap();

    return 0;
}
