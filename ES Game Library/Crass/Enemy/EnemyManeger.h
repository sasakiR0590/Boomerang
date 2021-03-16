#pragma once

#include"../../ESGLib.h"
#include"EnemyBase.h"
#include "StopEnemy.h"
#include"Enemy.h"

class EnemyManager {
public:
    EnemyManager::EnemyManager();
    EnemyManager::~EnemyManager();
    bool Initialize();
    int  Update();
    void Draw();
    void OnCollisionEnter(int);
    std::vector<EnemyBase*> GetEnemy() {return _enemy; }
private:
    void Generate();
    std::vector<EnemyBase*> _enemy;
    EnemyBase enemy_base;
    float time = 0;
};