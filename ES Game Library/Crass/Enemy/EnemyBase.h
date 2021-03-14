#pragma once

#include"..//..//ESGLib.h"

class EnemyBase {
public:
    EnemyBase::EnemyBase();
    EnemyBase::~EnemyBase();
    virtual bool Initialize() { return true; };
    virtual int  Update()     {return 0;}
    virtual void Draw()       {};
    MODEL GetCollision()      { return _collision; }
protected:
    Vector3 Move();
    Vector3 Angle();
    void    Damage();
     Vector3 _position;
    Vector3 _angle;
    int     _hp;
    MODEL   _collision;
    MODEL   _model;

};