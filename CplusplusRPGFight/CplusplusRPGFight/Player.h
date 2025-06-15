#pragma once
#include "Character.h"

class Player : public Character {
public:
    Player(std::string name, int hp, int str);
    void attack(Character& target) override;
};