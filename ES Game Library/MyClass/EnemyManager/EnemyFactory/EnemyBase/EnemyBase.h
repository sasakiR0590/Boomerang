#pragma once

#include "../../../../ESGLib.h"
#include"../../../PlayerManager/PlayerManeger.h"

class EnemyBase {
public:
    EnemyBase::EnemyBase();
    EnemyBase::~EnemyBase();
    virtual bool Initialize(Vector3 position, Vector3 speed, int hp);
    virtual int  Update(PlayerManager* playermanager);
    virtual void Draw()       {};
    MODEL GetCollision()      { return _collision; }
    Vector3 GetPosition()     { return _position; }
    void Damage();
    virtual int AutoDead();
protected:
    virtual void ChangeAnimation() = 0;
    bool IsDamage();
    Vector3 _position;
    Vector3 _angle;
    Vector3 _speed;
    Vector3 player_pos;
    int     _hp;
    MODEL   _collision;
    ANIMATIONMODEL   _model;

    SimpleShape shape;
    Material    mtrl;

    int     _animestate = 0;
    int     _oldanimestate = 0;
    float   _animation_count = 0.0f;
    float   _rotation = 0.0f;

    enum  ANIMESTATE
    {
        WAIT,
        RUN,
        ALLTYPE
    };
    enum { LIVING, DEATH };
private:
    enum {
        DAMAGE_STOP_FRAME = 30, AUTODEADTIME = 970
    };
    bool IsDead();
    int _destroy_time = 0;
    bool  damage_flag = false;
    float damage_frame = 0.0f;
};