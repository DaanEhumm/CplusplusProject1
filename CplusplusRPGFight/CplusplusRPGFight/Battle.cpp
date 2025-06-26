#include "Battle.h"
#include <iostream>
#include <ctime>
#include "GameManager.h"

Battle::Battle(Player* p, Enemy* e) : player(p), enemy(e) {
    srand(static_cast<unsigned int>(time(nullptr)));
}

void Battle::_printIntro() {
    GameManager::clearConsole();
    std::cout << "--- Battle ---\n";
    player->printStatus();
    enemy->printStatus();
    std::cout << "--------------------------\n\n";
}

void Battle::start() {
    GameManager::clearConsole();
    _printIntro();

    while (player->isAlive() && enemy->isAlive()) {
        player->resetDefend();
        enemy->resetDefend();

        enemyAction = enemy->chooseRandomAction();
        if (enemyAction == Action::Defend) {
            enemy->defend();
        }

        std::string playerLog;
        _playerTurn(playerLog);

        if (!enemy->isAlive()) break;

        std::string enemyLog;
        if (enemyAction == Action::Attack) {
            enemyLog += enemy->getName() + " kiest: Aanval\n";
            enemy->attack(*player, &enemyLog);
        }
        else {
            enemyLog += enemy->getName() + " kiest: Verdedigen\n";
        }

        std::cout << "\n--- Ronde Informatie ---\n";
        std::cout << playerLog;
        std::cout << enemyLog;

        std::cout << "\nStatus na deze ronde:\n";
        player->printStatus();
        enemy->printStatus();
        std::cout << "\n--------------------------\n";

        std::cout << "\nDruk op enter om verder te gaan...\n";
        std::cin.ignore();
        std::cin.get();

        GameManager::clearConsole();
        _printIntro();
    }

    if (player->isAlive())
        std::cout << "\nJe hebt gewonnen!\n";
    else
        std::cout << "\nJe bent verslagen...\n";
}

void Battle::_playerTurn(std::string& outLog) {
    std::cout << "\nWat wil je doen? (1 = Aanval, 2 = Verdedigen";
    if (player->canUseSpecial()) std::cout << ", 3 = Speciale Aanval";
    std::cout << "): ";

    int choice;
    std::cin >> choice;

    std::string log;

    if (choice == 1) {
        log += "Je koos: Aanval\n";
        player->attack(*enemy, &log);
    }
    else if (choice == 2) {
        player->defend();
        log += "Je koos: Verdedigen\n";
    }
    else if (choice == 3 && player->canUseSpecial()) {
        log += "Je koos: Speciale Aanval\n";
        log += player->getName() + " gebruikt een speciale aanval!\n";
        enemy->takeDamage(player->getStrength() * 2, &log);
    }
    else {
        log += "Ongeldige keuze. Je doet niets...\n";
    }

    outLog = log;
}
