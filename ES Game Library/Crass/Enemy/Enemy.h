#pragma once

#include"../../ESGLib.h"
#include "EnemyBase/EnemyBase.h"

class Enemy : public EnemyBase{
public:
    Enemy::Enemy();
    Enemy::~Enemy();
    bool   Initialize(Vector3 position, Vector3 speed, int hp) override;
    int    Update(PlayerManager* player_manager) override;
    void   Draw() override;
private:
    void    Move();
    void    ChangeAnimation() override;

    Vector3 player_pos;
};