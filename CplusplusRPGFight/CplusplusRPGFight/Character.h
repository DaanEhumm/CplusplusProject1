#pragma once
#include <string>
#include <iostream>

enum class Action {
    Attack,
    Defend
};

class Character {
protected:
    std::string name;
    int health;
    int strength;
    bool isDefending;

public:
    Character(std::string name, int hp, int str);
    virtual ~Character() = default;

    virtual void attack(Character& target) = 0;
    virtual void defend();
    virtual void takeDamage(int dmg);

    void resetDefend();
    bool isAlive() const;
    void printStatus() const;
    std::string getName() const;
};
