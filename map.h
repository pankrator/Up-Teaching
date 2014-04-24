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
    }

    Entity* getEntity(int x, int y) const { return entities[x + y * 10]; }

    void addEntity(Entity* entity);
    void move(int x, int y,Entity* ent);
};


#endif // MAP_H_INCLUDED
