#pragma once

#include "../EnemyBase/EnemyBase.h"

class HomingEnemy : public EnemyBase{
public:
    HomingEnemy::HomingEnemy();
    HomingEnemy::~HomingEnemy();
    int    Update(PlayerManager* player_manager) override;
    void   Draw();
private:
    void    Move();
    void    Rotate();
    void    ChangeAnimation() override;
};