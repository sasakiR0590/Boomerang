#pragma once

#include "../EnemyBase/EnemyBase.h"

/**
 * @file   StopEnemy.h
 * @brief  �����Ȃ��G�N���X
 * @author Mitsuhide Kowata
 * @date �@2021/03/31
 */

class StopEnemy : public EnemyBase{
public:
    StopEnemy::StopEnemy();
    StopEnemy::~StopEnemy();
    int    Update(PlayerManager* player_manager) override;
private:
};