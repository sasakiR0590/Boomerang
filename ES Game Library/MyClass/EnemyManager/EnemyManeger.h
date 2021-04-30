#pragma once

#include "EnemyFactory/EnemyFactory.h"

class EnemyManager {
public:
    EnemyManager::EnemyManager();
    EnemyManager::~EnemyManager();
    bool Initialize();
    int  Update(PlayerManager* playermanager);
    void Draw();
    void OnCollisionEnter(EnemyBase*);
    std::list<EnemyBase*> GetEnemy() {return _enemy; }
    enum {LIVING,DEATH};

private:
    void Generate(PlayerManager* player_manager);
    void LoadCSV();

    std::list<EnemyBase*> _enemy;
    float _frame = 0.0f;
    float _time  = 0.0f;

    enum { MOVE_ENEMY, STOP_ENEMY,HOMING_ENEMY,DIST_HOMING_ENEMY };
    enum { ENEMY_NUM = 100 };
   
    int count = 0;                   //敵の累計出現数カウント 
    int     tag[ENEMY_NUM];          //敵の種類         
    Vector3 appear_pos[ENEMY_NUM];   //敵の出現座標  
    float   appear_time[ENEMY_NUM];  //敵の出現時間
    bool    appear_flag[ENEMY_NUM];  //敵の出現フラグ 
};