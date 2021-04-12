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
   
    int count = 0;                   //�G�̗݌v�o�����J�E���g 
    int     tag[ENEMY_NUM];          //�G�̎��         
    Vector3 appear_pos[ENEMY_NUM];   //�G�̏o�����W  
    int     appear_time[ENEMY_NUM];  //�G�̏o������
    bool    appear_flag[ENEMY_NUM];  //�G�̏o���t���O 
};