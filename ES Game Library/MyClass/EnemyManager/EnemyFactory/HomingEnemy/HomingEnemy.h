#pragma once

/**
 * @file   HomingEnemy.h
 * @brief  �z�[�~���O����G�N���X
 * @author Mitsuhide Kowata
 * @date �@2021/03/31
 */

#include "../EnemyBase/EnemyBase.h"

class HomingEnemy : public EnemyBase{
public:
    HomingEnemy::HomingEnemy();
    HomingEnemy::~HomingEnemy();
    int    Update(PlayerManager* player_manager) override;
private:
    void    Move();
    void    Rotate();
};