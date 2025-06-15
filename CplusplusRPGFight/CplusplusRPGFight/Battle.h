#pragma once
#include "Player.h"
#include "Enemy.h"

class Battle {
private:
    Player player;
    Enemy enemy;

public:
    Battle(Player p, Enemy e);
    void start();

private:
    void _printIntro();
    void _playerTurn();
    void _enemyTurn();
};

