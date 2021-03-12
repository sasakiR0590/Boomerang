#pragma once

#include"..//..//ESGLib.h"

class Enemy {
public:
    Enemy::Enemy();
    Enemy::~Enemy();
    bool   Initialize();
    int    Update();
    void   Draw();
private:
    void    Move();
};