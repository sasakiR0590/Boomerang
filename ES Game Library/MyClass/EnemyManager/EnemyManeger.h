#pragma once

/**
 * @file   EnemyManager.h
 * @brief  �G���Ď�����N���X
 * @author Mitsuhide Kowata
 * @date �@2021/03/31
 */

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

private:
    void Generate(PlayerManager* player_manager);
    void LoadCSV();

    std::list<EnemyBase*> _enemy;
    float _frame = 0.0f;
    float _time  = 0.0f;

    /**
�@�@* @enum EnemyState
�@�@* �G�̏�ԕω��p
�@�@*/
    enum EnemyState { LIVING,DESTROY, DEATH };

    /**
�@�@* @enum LoadFile
�@�@* �t�@�C���ǂݍ��ݗp
�@�@*/
    enum LoadFile{ DUMMYLINENUM = 3,ENEMY_NUM = 250 };

    /**
�@�@* @enum Frame
�@�@* �G�̏o�����Ԍv���p
�@�@*/
    enum Frame{ GAME_FRAME = 60 };
   
    int count = 0;                   //!�G�̗݌v�o�����J�E���g 
    string  tag[ENEMY_NUM];          //!�G�̎��         
    Vector3 appear_pos[ENEMY_NUM];   //!�G�̏o�����W  
    float   appear_time[ENEMY_NUM];  //!�G�̏o������
    bool    appear_flag[ENEMY_NUM];  //!�G�̏o���t���O 
    SOUND explode;

    PlayerManager* _playermanager;
};