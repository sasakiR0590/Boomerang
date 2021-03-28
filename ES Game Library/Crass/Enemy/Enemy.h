#pragma once

#include"../../ESGLib.h"
#include "EnemyBase.h"
#include "EnemyManeger.h"

class Enemy : public EnemyBase{
public:
    Enemy::Enemy();
    Enemy::~Enemy();
    bool   Initialize(Vector3 speed, int hp) override;
    int    Update() override;
    void   Draw() override;
private:
    void    Move();
    void    ChangeAnimation() override;
};