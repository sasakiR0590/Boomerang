#pragma once

#include"../../ESGLib.h"
#include"EnemyBase.h"
#include"Enemy.h"

class EnemyManeger {
public:
    EnemyManeger::EnemyManeger();
    EnemyManeger::~EnemyManeger();
    bool Initialize();
    int  Update();
    void Draw();
private:
    void Generate();
    void OnCollisionEnter();

    std::vector<EnemyBase*> _enemy;
    float time = 0;
};