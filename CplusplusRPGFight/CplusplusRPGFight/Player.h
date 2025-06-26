#pragma once
#include "Character.h"
#include "PlayerClass.h"


class Player : public Character {
private:
    bool hasUsedSpecial;
    PlayerClass playerClass;

public:
    Player(std::string name, PlayerClass type);
    void attack(Character& target, std::string* log);
    void specialAttack(Character& target, std::string* log);
    bool canUseSpecial() const;
};