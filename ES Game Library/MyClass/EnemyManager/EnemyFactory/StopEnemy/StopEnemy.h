#pragma once

#include "../EnemyBase/EnemyBase.h"

class StopEnemy : public EnemyBase{
public:
    StopEnemy::StopEnemy();
    StopEnemy::~StopEnemy();
    int    Update(PlayerManager* player_manager) override;
    void   Draw();
private:
    void ChangeAnimation() override;
};