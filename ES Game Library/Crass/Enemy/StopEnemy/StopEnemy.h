#pragma once

#include "../../../ESGLib.h"
#include "../EnemyBase/EnemyBase.h"
#include "../EnemyManager/EnemyManeger.h"

class StopEnemy : public EnemyBase{
public:
    StopEnemy::StopEnemy();
    StopEnemy::~StopEnemy();
    bool   Initialize(Vector3 position, Vector3 speed, int hp) override;
    int    Update(PlayerManager* player_manager) override;
    void   Draw() override;
private:
    void ChangeAnimation() override;
    int destroy_time = 0;
};