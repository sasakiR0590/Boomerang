#pragma once

#include "../../EnemyManeger.h"
#include "../EnemyBase/EnemyBase.h"

class NormalEnemy : public EnemyBase{
public:
    NormalEnemy:: NormalEnemy();
    NormalEnemy::~NormalEnemy();
    bool   Initialize(Vector3 position, Vector3 speed, int hp) override;
    int    Update(PlayerManager* player_manager) override;
    void   Draw() override;
private:
    void    Move();
    void    ChangeAnimation() override;

    Vector3 player_pos;
};