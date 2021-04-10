#pragma once

#include"..//..//ESGLib.h"

class EnemyBase {
public:
    EnemyBase::EnemyBase();
    EnemyBase::~EnemyBase();
    virtual bool Initialize(Vector3 position, Vector3 speed, int hp) { return true; };
    virtual int  Update();
    virtual void Draw()       {};
    MODEL GetCollision()      { return _collision; }
    Vector3 GetPosition()     { return _position; }
    Vector3 EnemyPosition(Vector3 pos);
    void Damage();
protected:
    Vector3 _position;
    Vector3 _angle;
    Vector3 _speed;
    int     _hp;
    MODEL   _collision;
    ANIMATIONMODEL   _model;

    virtual void ChangeAnimation() = 0;
    int     _animestate = 0;
    int     _oldanimestate = 0;
    float   _animation_count = 0.0f;
    enum  ANIMESTATE
    {
        WAIT,
        RUN,
        ALLTYPE
    };
};