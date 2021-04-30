#pragma once

#include "../EnemyBase/EnemyBase.h"

class HomingEnemy : public EnemyBase{
public:
    HomingEnemy::HomingEnemy();
    HomingEnemy::~HomingEnemy();
    bool   Initialize(Vector3 position, Vector3 speed, int hp) override;
    int    Update(PlayerManager* player_manager) override;
    void   Draw() override;
private:
    void    Move();
    void    ChangeAnimation() override;

    Vector3 player_pos;
    int destroy_time = 0;
};