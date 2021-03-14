#pragma once

#include"../../ESGLib.h"
#include "EnemyBase.h"

class StopEnemy : public EnemyBase{
public:
    StopEnemy::StopEnemy();
    StopEnemy::~StopEnemy();
    bool   Initialize() override;
    int    Update() override;
    void   Draw() override;
private:

};