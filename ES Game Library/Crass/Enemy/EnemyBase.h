#pragma once

#include"..//..//ESGLib.h"

class EnemyBase {
public:
    EnemyBase::EnemyBase();
    EnemyBase::~EnemyBase();
    virtual bool Initialize() { return true; };
    virtual int  Update();
    virtual void Draw()       {};
    MODEL GetCollision()      { return _collision; }
    Vector3 GetPosition()     { return _position; }
    void    Damage();
protected:
    Vector3 Move();
    Vector3 Angle();
     Vector3 _position;
    Vector3 _angle;
    int     _hp;
    MODEL   _collision;
    MODEL   _model;
};