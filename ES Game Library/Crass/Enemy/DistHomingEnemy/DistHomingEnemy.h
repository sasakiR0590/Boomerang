#pragma once

#include"../../../ESGLib.h"
#include "../EnemyBase/EnemyBase.h"
#include "../EnemyManager/EnemyManeger.h"

class DistHomingEnemy : public EnemyBase{
public:
    DistHomingEnemy::DistHomingEnemy();
    DistHomingEnemy::~DistHomingEnemy();
    bool   Initialize(Vector3 position, Vector3 speed, int hp) override;
    int    Update() override;
    void   Draw() override;
private:
    void    Move();
    void    ChangeAnimation() override;

    Vector3 player_pos;
};