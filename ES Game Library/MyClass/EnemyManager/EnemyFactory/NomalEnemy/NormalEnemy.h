#pragma once

#include "../../EnemyManeger.h"
#include "../EnemyBase/EnemyBase.h"

class NormalEnemy : public EnemyBase{
public:
    NormalEnemy:: NormalEnemy();
    NormalEnemy::~NormalEnemy();
    int    Update(PlayerManager* player_manager) override;
    void   Draw();
private:
    void    Move();
    void    ChangeAnimation() override;

    Vector3 player_pos;
    const float enemy_living_area_z = -8.8f;
};