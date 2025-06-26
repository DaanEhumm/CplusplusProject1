#pragma once
#include "Player.h"
#include "Enemy.h"

class Battle {
private:
    Player* player;
    Enemy* enemy;

public:
    Battle(Player* p, Enemy* e);
    void start();
    std::string lastDamageInfo;
    std::string lastRoundLog; 
	Action enemyAction;

private:
    void _printIntro();
    void _playerTurn(std::string& enemyDamageLog);
};

