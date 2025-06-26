#include "Enemy.h"
#include <cstdlib>

Enemy::Enemy(std::string name, int hp, int str)
    : Character(name, hp, str, 0) {
	defenseBonus = 4; 
};

void Enemy::attack(Character& target, std::string* log) {
    if (log) *log += name + " valt aan!\n";
    target.takeDamage(strength, log);
}

Action Enemy::chooseRandomAction() {
    return static_cast<Action>(rand() % 2);
}