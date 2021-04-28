#pragma once

#include"../../../ESGLib.h"
#include "../EnemyBase/EnemyBase.h"
#include "../EnemyManager/EnemyManeger.h"
#include "../../Player/PlayerManeger.h"

class HomingEnemy : public EnemyBase{
public:
    HomingEnemy::HomingEnemy();
    HomingEnemy::~HomingEnemy();
    bool   Initialize(Vector3 position, Vector3 speed, int hp) override;
    int    Update() override;
    void   Draw() override;
private:
    void    Move();
    void    ChangeAnimation() override;


    Vector3 player_pos;
    PlayerManager pm;
};