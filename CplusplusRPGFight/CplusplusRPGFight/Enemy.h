#pragma once
#include "Character.h"

class Enemy : public Character {
public:
    Enemy(std::string name, int hp, int str);
    void attack(Character& target, std::string* log);
    Action chooseRandomAction();
};
