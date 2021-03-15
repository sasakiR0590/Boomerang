#pragma once

#include"../../ESGLib.h"
#include"EnemyBase.h"
#include "StopEnemy.h"
#include"Enemy.h"

class EnemyManeger {
public:
    EnemyManeger::EnemyManeger();
    EnemyManeger::~EnemyManeger();
    bool Initialize();
    int  Update();
    void Draw();
    void OnCollisionEnter(int);
    std::vector<EnemyBase*> GetEnemy() {return _enemy; }
private:
    void Generate();
    std::vector<EnemyBase*> _enemy;
    EnemyBase eb;
    float time = 0;
};