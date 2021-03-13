#pragma once

#include"../../ESGLib.h"
#include"Boomerang.h"

class PlayerManeger {
public:
    PlayerManeger::PlayerManeger();
    PlayerManeger::~PlayerManeger();

    bool    Initialize();
    int     Update();
    void    Draw();

    Vector3 Position();
    Vector3 GetFrontVector();
    Vector3 GetUpVector();
    MODEL GetCollision() { return _collision; }

    void    Shoot();
private:
    Vector3 Move();
    Vector3 Angle();
    int     Power();
    void    Damage();
    void    OnCollisionEnter();

    Vector3    _position;
    Vector3    _angle;
    int        _power;
    int        _hp;
    bool       _shootstate;
    Boomerang* _boomerang;

    MODEL      _collision;
    MODEL      _model;
};