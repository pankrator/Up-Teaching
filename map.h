#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <iostream>
#include "entity.h"

using namespace std;

class Entity;
class Map
{
private:
    Entity** entities;

public:
    Map()
    {
       entities = new Entity*[100];
       for(int i = 0; i < 100; i++)
       {
           entities[i] = NULL;
        }
    }

    Entity* getEntity(int x, int y) const { return entities[x + y * 10]; }

    void addEntity(Entity* entity);
    void move(int x, int y,Entity* ent);
    void printMap();
};


#endif // MAP_H_INCLUDED
