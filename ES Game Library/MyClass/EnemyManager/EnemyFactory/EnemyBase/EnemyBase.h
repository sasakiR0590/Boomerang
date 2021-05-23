#pragma once

#include "../../../../ESGLib.h"
#include"../../../PlayerManager/PlayerManeger.h"
#include "../../../TimeManager/TimeManager.h"

class EnemyBase {
public:
    EnemyBase::EnemyBase();
    EnemyBase::~EnemyBase();
    virtual bool Initialize(string _model_name, Vector3 position, Vector3 speed, int hp);
    virtual int  Update(PlayerManager* playermanager);
    void Draw();
    MODEL GetCollision() { return _collision; }
    Vector3 GetPosition() { return _position; }
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

    int     _animestate = 0;
    int     _oldanimestate = 0;
    double   _animation_count = 0.0;
    float   _rotation = 0.0f;
    const float  _homing_area = 8.5f;

    enum  ANIMESTATE
    {
        WAIT,
        RUN,
        ALLTYPE
    };
    enum { LIVING, DEATH };
private:
    enum { DAMAGE_STOP_FRAME = 30, AUTODEADTIME = 900 };
    bool IsDead();
    bool LimitDestruction();
    int _destroy_time = 0;
    bool  damage_flag = false;
    float damage_frame = 0.0f;

    const float time_over = 0.9f;
};