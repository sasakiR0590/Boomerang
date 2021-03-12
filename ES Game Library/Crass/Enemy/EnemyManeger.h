#pragma once

#include"..//..//ESGLib.h"
#include"EnemyBase.h"

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
};