#pragma once

#include "../EnemyBase/EnemyBase.h"

class StopEnemy : public EnemyBase{
public:
    StopEnemy::StopEnemy();
    StopEnemy::~StopEnemy();
    bool   Initialize(Vector3 position, Vector3 speed, int hp) override;
    int    Update(PlayerManager* player_manager) override;
    void   Draw() override;
private:
    void ChangeAnimation() override;
};