#pragma once

#include "../EnemyBase/EnemyBase.h"

class DistHomingEnemy : public EnemyBase{
public:
    DistHomingEnemy::DistHomingEnemy();
    DistHomingEnemy::~DistHomingEnemy();
    int    Update(PlayerManager* player_manager) override;
    void   Draw();
private:
    void    Move();
    void    Rotate();
    void    ChangeAnimation() override;

    Vector3 player_pos;
    bool homing_flag = false;
    enum { DIST_POS = 7 };
};