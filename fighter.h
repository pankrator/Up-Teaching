#ifndef FIGHT_H_INCLUDED
#define FIGHT_H_INCLUDED

#include <string>

using namespace std;

enum MagicType
{
    Fireball,
    Freeze,
    Frenzy
};

enum HeroType
{
    Magician,
    Warrior
};


class Fighter
{
private:
    string name;
    int numOfPotions;
    int damage;
    int manaPoints;
    int health;
    bool freezed;
    bool turn;
    bool frenzy;
    MagicType used;

    void create(HeroType);
    void takeHealth(int amount);

public:
    HeroType type;

    Fighter(HeroType className, string name) : name(name), type(className)
    {
        this->freezed = false;
        this->turn = true;
        this->frenzy = false;
        this->used = Frenzy;
        this->create(className);
    }

    /**
        Use the following three functions only
    **/
    void usePotion();
    void attack(Fighter* other);
    void useMagic(MagicType magicType, Fighter* other);

    /**
        Override this function to modify your fight logic as you want using
        the three functions above
    **/
    virtual void fight(Fighter* other) = 0;

    /** GETTERS **/
    string getName() const { return this->name; }
    int getHealth() const { return this->health; }
    bool isFreezed() const { return this->freezed; }
    bool getTurn() const { return this->turn; }

    /** SETTERS **/
    void setTurn(bool turn) { this->turn = turn; }
    void setFreezed(bool freeze) { this->freezed = freeze; }

};

#endif // FIGHT_H_INCLUDED
