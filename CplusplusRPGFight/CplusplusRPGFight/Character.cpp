#include "Character.h"

Character::Character(std::string name, int hp, int str, int def)
    : name(name), health(hp), strength(str), defenseBonus(def), isDefending(false) {
}

void Character::defend(std::string* log) {
    isDefending = true;
    if (log) {
        *log += name + " kiest: Verdedigen\n";
    }
}

void Character::takeDamage(int dmg, std::string* log) {
    int finalDamage = dmg;

    std::string msg;

    if (isDefending) {
        finalDamage -= defenseBonus;
        if (finalDamage < 0) finalDamage = 0;

        msg = name + " verdedigt zich en ontvangt " + std::to_string(finalDamage) + " schade.";
    }
    else {
        msg = name + " ontvangt " + std::to_string(finalDamage) + " schade.";
    }

    health -= finalDamage;

    if (log) {
        *log += msg + "\n"; 
    }
}

void Character::resetDefend() {
    isDefending = false;
}

bool Character::isAlive() const {
    return health > 0;
}

void Character::printStatus() const {
    std::cout << name << " | HP: " << health << " | STR: " << strength << "\n";
}

std::string Character::getName() const {
    return name;
}