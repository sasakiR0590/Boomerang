#pragma once

#include"../../../ESGLib.h"
#include "../EnemyBase/EnemyBase.h"
#include "../EnemyManager/EnemyManeger.h"

class Enemy : public EnemyBase{
public:
    Enemy::Enemy();
    Enemy::~Enemy();
    bool   Initialize(Vector3 position, Vector3 speed, int hp) override;
    int    Update() override;
    void   Draw() override;
private:
    void    Move();
    void    ChangeAnimation() override;

    enum {HOMING,DIST_HOMING,RUN};

    Vector3 player_pos;
};