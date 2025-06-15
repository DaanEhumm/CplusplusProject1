#include "GameManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Battle.h"

void GameManager::RunBattle() {
    Player p("Dude", 100, 20);
    Enemy e("Zombie", 80, 15);
    Battle b(p, e);
    b.start();
}
