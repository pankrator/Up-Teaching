#include "map.h"
#include "entity.h"

void Map::move(int x, int y,Entity* ent)
{
    entities[ent->getX() + ent->getY() * 10] = NULL;
    entities[x + y * 10] = ent;
}

void Map::addEntity(Entity* entity)
{
    entities[entity->getX() + entity->getY() * 10] = entity;
}

void Map::printMap()
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(this->entities[i + j * 10] == NULL)
            {
                cout<<"---  ";
                continue;
            }
            cout<<this->entities[i + j * 10]->getName()<<" ";
        }
        cout<<endl;
    }
}
