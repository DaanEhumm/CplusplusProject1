#include "Battle.h"
#include <iostream>
#include <ctime>

Battle::Battle(Player p, Enemy e) : player(p), enemy(e) {
    srand(static_cast<unsigned int>(time(nullptr)));
}

void Battle::_printIntro() {
    std::cout << "--- Battle ---\n";
    player.printStatus();
    enemy.printStatus();
    std::cout << "--------------------------\n\n";
}

void Battle::start() {
    _printIntro();

    while (player.isAlive() && enemy.isAlive()) {
        _playerTurn();
        if (!enemy.isAlive()) break;

        _enemyTurn();

        player.resetDefend();
        enemy.resetDefend();

        std::cout << "\nStatus na deze ronde:\n";
        player.printStatus();
        enemy.printStatus();
        std::cout << "\n--------------------------\n";
    }

    if (player.isAlive())
        std::cout << "\nJe hebt gewonnen!\n";
    else
        std::cout << "\nJe bent verslagen...\n";
}

void Battle::_playerTurn() {
    std::cout << "\nWat wil je doen? (1 = Aanvallen, 2 = Verdedigen): ";
    int Choice;
    std::cin >> Choice;

    if (Choice == 1) {
        player.attack(enemy);
    }
    else if (Choice == 2) {
        player.defend();
    }
    else {
        std::cout << "Ongeldige keuze. Je doet niets...\n";
    }
}

void Battle::_enemyTurn() {
    Action act = enemy.chooseRandomAction();
    if (act == Action::Attack) {
        enemy.attack(player);
    }
    else {
        enemy.defend();
    }
}
