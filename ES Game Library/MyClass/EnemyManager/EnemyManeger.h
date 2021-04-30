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
   
    int count = 0;                   //�G�̗݌v�o�����J�E���g 
    int     tag[ENEMY_NUM];          //�G�̎��         
    Vector3 appear_pos[ENEMY_NUM];   //�G�̏o�����W  
    float   appear_time[ENEMY_NUM];  //�G�̏o������
    bool    appear_flag[ENEMY_NUM];  //�G�̏o���t���O 
};