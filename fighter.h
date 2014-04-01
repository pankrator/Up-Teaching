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
    bool turn;
    bool frenzy;

    void create(HeroType);
    void takeHealth(int amount);

public:
    Fighter() {}

    Fighter(HeroType className)
    {
        this->freezed = false;
        this->turn = true;
        this->frenzy = false;
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
    int getHealth() const { return this->health; }
    bool isFreezed() const { return this->freezed; }
    bool getTurn() const { return this->turn; }

    /** SETTERS **/
    void setTurn(bool turn) { this->turn = turn; }
    void setFreezed(bool freeze) { this->freezed = freeze; }

};

#endif // FIGHT_H_INCLUDED
