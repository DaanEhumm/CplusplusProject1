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
    int defenseBonus;
    bool isDefending;

public:
    Character(std::string name, int hp, int str, int def);
    virtual ~Character() = default;

    virtual void attack(Character& target, std::string* log = nullptr) = 0;
    virtual void defend(std::string* log = nullptr);
    virtual void takeDamage(int dmg, std::string* log = nullptr);

    void resetDefend();
    bool isAlive() const;
    void printStatus() const;
    std::string getName() const;
    int getStrength() const { return strength; }

	void clearConsole() {
		system("cls");
	}
};
