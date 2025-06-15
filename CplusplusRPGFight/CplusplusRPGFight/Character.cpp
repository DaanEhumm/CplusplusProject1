#include "Character.h"

Character::Character(std::string name, int hp, int str)
    : name(name), health(hp), strength(str), isDefending(false) {
}

void Character::defend() {
    isDefending = true;
    std::cout << name << " verdedigt zich!\n";
}

void Character::takeDamage(int dmg) {
    int finalDamage = isDefending ? dmg / 2 : dmg;
    health -= finalDamage;
    std::cout << name << " ontvangt " << finalDamage << " schade.\n";
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