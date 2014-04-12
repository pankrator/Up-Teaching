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
