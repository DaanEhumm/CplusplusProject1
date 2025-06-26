#include "GameManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Battle.h"
#include <iostream>
#include <windows.h>

void GameManager::RunBattle() {
    std::cout << "Kies je klasse:\n";
    std::cout << "1. Warrior (20 STR, 7 DEF)\n";
    std::cout << "2. Berserker (25 STR, 2 DEF)\n";
    int choice;
    std::cin >> choice;
    clearConsole();
    PlayerClass selectedClass = (choice == 2) ? PlayerClass::Berserker : PlayerClass::Warrior;
    
    std::string playerName;

    if (selectedClass == PlayerClass::Warrior) {
        playerName = "Warrior";
    }
    else {
        playerName = "Berserker";
    }

    Player* p = new Player(playerName, selectedClass);
    Enemy* e = new Enemy("Zombie", 80, 15);
    Battle b(p, e);
    b.start();

    delete p;
    delete e;
}
