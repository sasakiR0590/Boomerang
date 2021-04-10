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
    void LoadPosition_AppearTimeCSV();

    std::list<EnemyBase*> _enemy;
    int _time = 0;

    //!�����G�L�����̃X�e�[�^�X
    Vector3 _moveenemy_speed;
    int     _moveenemy_hp;

    //!�����Ȃ��G�L�����̃X�e�[�^�X
    Vector3 _stopenemy_speed;
    int     _stopenemy_hp;

    enum { MOVE_ENEMY, STOP_ENEMY };
    enum { ENEMY_NUM = 100 };
   
    //�G�̗݌v�o�����J�E���g�A��ށA�o�����W�A�o�����ԁA�o���t���O
    int count = 0;                    
    int     tag[ENEMY_NUM];           
    Vector3 appear_pos[ENEMY_NUM];    
    int     appear_time[ENEMY_NUM];   
    bool    appear_flag[ENEMY_NUM];   
};