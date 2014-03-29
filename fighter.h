#ifndef FIGHT_H_INCLUDED
#define FIGHT_H_INCLUDED

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
    int numOfPotions;
    int damage;
    int manaPoints;
    int health;
    bool freezed;

    void create(HeroType);
    void takeHealth(int amount);

public:
    Fighter(HeroType className)
    {
        this->freezed = false;
        this->create(className);
    }

    /**
        Use the following three functions only
    **/
    int usePotion();
    int attack(Fighter* other);
    int useMagic(MagicType magicType, Fighter* other);

    /**
        Override this function to modify your fight logic as you want using
        the three functions above
    **/
    virtual int fight(Fighter* other) = 0;

    /** GETTERS **/
    int getHealth() const { return this->health; }
};


#endif // FIGHT_H_INCLUDED
