#pragma once

#include"../../ESGLib.h"
#include "EnemyBase.h"

class Enemy : public EnemyBase{
public:
    Enemy::Enemy();
    Enemy::~Enemy();
    bool   Initialize() override;
    int    Update() override;
    void   Draw() override;
private:
    void    Move();
};