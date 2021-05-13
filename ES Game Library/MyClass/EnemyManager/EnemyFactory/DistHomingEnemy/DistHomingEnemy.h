#pragma once

#include "../EnemyBase/EnemyBase.h"

class DistHomingEnemy : public EnemyBase{
public:
    DistHomingEnemy::DistHomingEnemy();
    DistHomingEnemy::~DistHomingEnemy();
    bool   Initialize(Vector3 position, Vector3 speed, int hp) override;
    int    Update(PlayerManager* player_manager) override;
    void   Draw() override;
private:
    void    Move();
    void    Rotate();
    void    ChangeAnimation() override;

    Vector3 player_pos;
    bool homing_flag = false;

};