#include "Enemy.h"
#include <cstdlib>

Enemy::Enemy(std::string name, int hp, int str)
    : Character(name, hp, str) {
}

void Enemy::attack(Character& target) {
    std::cout << name << " valt aan!\n";
    target.takeDamage(strength);
}

Action Enemy::chooseRandomAction() {
    return static_cast<Action>(rand() % 2);
}