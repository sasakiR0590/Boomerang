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
    void LoadCSV();
    std::vector<EnemyBase*> _enemy;
    float _time = 0;

    //!動く敵キャラのステータス
    Vector3 _moveenemy_speed;
    int     _moveenemy_hp;

    //!動かない敵キャラのステータス
    Vector3 _stopenemy_speed;
    int     _stopenemy_hp;
};