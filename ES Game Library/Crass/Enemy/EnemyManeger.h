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

  // string MOVE_ENEMY = "move_enemy";
  // string STOP_ENEMY = "stop_enemy";
private:
    void Generate();
    void LoadCSV();

    std::list<EnemyBase*> _enemy;
    int _time = 0;

    enum { MOVE_ENEMY, STOP_ENEMY };
    enum { ENEMY_NUM = 100 };
   
    int count = 0;                   //敵の累計出現数カウント 
    int     tag[ENEMY_NUM];          //敵の種類         
    Vector3 appear_pos[ENEMY_NUM];   //敵の出現座標  
    int     appear_time[ENEMY_NUM];  //敵の出現時間
    bool    appear_flag[ENEMY_NUM];  //敵の出現フラグ 
};