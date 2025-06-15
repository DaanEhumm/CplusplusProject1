#include "Player.h"

Player::Player(std::string name, int hp, int str)
    : Character(name, hp, str) {
}

void Player::attack(Character& target) {
    std::cout << name << " valt aan!\n";
    target.takeDamage(strength);
}
