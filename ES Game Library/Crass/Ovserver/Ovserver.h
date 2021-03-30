#pragma once

#include"../../ESGLib.h"
#include"../Player/PlayerManeger.h"
#include"../Enemy/EnemyManeger.h"
class Ovserver {
public:
    Ovserver::Ovserver();
    Ovserver::~Ovserver();
    int     Update(PlayerManager*, EnemyManager*);
    void    ColisionDetection(PlayerManager* playerdata, EnemyManager* enemydata);
private:
};