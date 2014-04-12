#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include<string>
#include "weapon.h"

using namespace std;

class Map;
class Entity
{
private:
    Weapon weapon;
    string name;
    int health;
    int x, y;
    bool isEquiped;

public:

    Entity() {}

    Entity(string name, int health, int x, int y) : x(x), y(y)
    {
        this->isEquiped = false;
        this->name = name;
        this->health = health;
    }

    bool isAlive();
    void takeDamage(float damage);
    void takeHealing(int healPoints);
    void equipWeapon(const Weapon& weap);
    bool move(int x, int y, Map* board);

    virtual int attack() = 0;
    virtual string instanceOf() const = 0;

    /** GETTERS **/
    int getX() const { return x; }

    int getY() const { return y; }

    string getName() const { return name; }

    bool getIsEquiped() const { return this->isEquiped; }

    int getHealth() const { return this->health; }

    Weapon getWeapon() const { return this->weapon; }

    /** SETTERS **/
    void setX(int x) { this->x = x;}
    void setY(int y) { this->y = y;}
};


#endif // ENTITY_H_INCLUDED
