#pragma once

/**
 * @file   DistHomingEnemy.h
 * @brief  ��苗���Ńz�[�~���O����G�N���X
 * @author Mitsuhide Kowata
 * @date �@2021/03/31
 */

#include "../EnemyBase/EnemyBase.h"

class DistHomingEnemy : public EnemyBase{
public:
    DistHomingEnemy::DistHomingEnemy();
    DistHomingEnemy::~DistHomingEnemy();
    int    Update(PlayerManager* player_manager) override;
private:
    void    Move();
    void    Rotate();

    Vector3 player_pos;
    bool homing_flag = false;

    /**
    * @enum Pos
    * �z�[�~���O�J�n����
    */
    enum Pos { DIST_POS = 3 };
};