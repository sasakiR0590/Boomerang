#pragma once

/**
 * @file   NormalEnemy.h
 * @brief  �^�������i�ޓG�N���X
 * @author Mitsuhide Kowata
 * @date �@2021/03/31
 */

#include "../../EnemyManeger.h"
#include "../EnemyBase/EnemyBase.h"

class NormalEnemy : public EnemyBase{
public:
    NormalEnemy:: NormalEnemy();
    NormalEnemy::~NormalEnemy();
    int    Update(PlayerManager* player_manager) override;
private:
    void    Move();

    Vector3 player_pos;
    const float enemy_living_area_z = -8.8f;
};