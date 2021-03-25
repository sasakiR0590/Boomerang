#pragma once

#include"../../ESGLib.h"
#include "EnemyBase.h"

class StopEnemy : public EnemyBase{
public:
    StopEnemy::StopEnemy();
    StopEnemy::~StopEnemy();
    bool   Initialize(Vector3 speed, int hp) override;
    int    Update() override;
    void   Draw() override;
private:
    int destroy_time = 0;
};