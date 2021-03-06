#pragma once

#include"..//..//ESGLib.h"
#include"Boomerang.h"

class PlayerManeger {
public:
    PlayerManeger::PlayerManeger();
    PlayerManeger::~PlayerManeger();

    bool    Initialize();
    int     Update();
    void    Draw();
private:
    Vector3 Move();
    Vector3 Angle();
    int     Power();
    void    Shoot();
    void    Damage();
    void    OnCollisionEnter();

    Vector3    _position;
    Vector3    _angle;
    int        _power;
    int        _hp;
    bool       _shootstate;
    Boomerang* _boomerang;
    MODEL      _colision;
    MODEL      _model;

};