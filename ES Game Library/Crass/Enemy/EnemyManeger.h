#pragma once

#include"../../ESGLib.h"
#include "EnemyFactory.h"

class EnemyManager {
public:
    EnemyManager::EnemyManager();
    EnemyManager::~EnemyManager();
    bool Initialize();
    int  Update();
    void Draw();
    void OnCollisionEnter(EnemyBase*);
    std::list<EnemyBase*> GetEnemy() {return _enemy; }
    enum {LIVING,DEATH};

   string MOVE_ENEMY = "move_enemy";
   string STOP_ENEMY = "stop_enemy";
private:
    void Generate();
    void LoadCSV();
    std::list<EnemyBase*> _enemy;
    float _time = 0;

    //!動く敵キャラのステータス
    Vector3 _moveenemy_speed;
    int     _moveenemy_hp;

    //!動かない敵キャラのステータス
    Vector3 _stopenemy_speed;
    int     _stopenemy_hp;
};