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
    void OnCollisionEnter(EnemyBase*);
    std::list<EnemyBase*> GetEnemy() {return _enemy; }
    enum {LIVING,DEATH};
private:
    void Generate();
    void LoadCSV();
    std::list<EnemyBase*> _enemy;
    float _time = 0;

    //!�����G�L�����̃X�e�[�^�X
    Vector3 _moveenemy_speed;
    int     _moveenemy_hp;

    //!�����Ȃ��G�L�����̃X�e�[�^�X
    Vector3 _stopenemy_speed;
    int     _stopenemy_hp;
};