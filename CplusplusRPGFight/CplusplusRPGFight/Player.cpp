#include "Player.h"
#include <iostream>

Player::Player(std::string name, PlayerClass type)
    : Character(name, 100, type == PlayerClass::Warrior ? 20 : 25,
        type == PlayerClass::Warrior ? 7 : 2),
    playerClass(type), hasUsedSpecial(false)
{
    switch (type) {
    case PlayerClass::Warrior:
        strength = 20;
        defenseBonus = 7;
        break;
    case PlayerClass::Berserker:
        strength = 25;
        defenseBonus = 2;
        break;
    }
}

void Player::attack(Character& target, std::string* log) {
    if (log) *log += name + " valt aan!\n";
    target.takeDamage(strength, log);
}

void Player::specialAttack(Character& target, std::string* log) {
    if (!hasUsedSpecial) {
        if (log) *log = name + " gebruikt een speciale aanval!\n";
        target.takeDamage(strength * 2, log);
        hasUsedSpecial = true;
    }
    else {
        if (log) *log = "Je hebt je speciale aanval al gebruikt!\n";
        else std::cout << "Je hebt je speciale aanval al gebruikt!\n";
    }
}

bool Player::canUseSpecial() const {
    return !hasUsedSpecial;
}