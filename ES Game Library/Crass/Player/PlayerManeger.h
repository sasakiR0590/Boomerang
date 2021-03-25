#pragma once

#include"../../ESGLib.h"
#include"Boomerang.h"

class PlayerManager {
public:
    PlayerManager::PlayerManager();
    PlayerManager::~PlayerManager();

    bool    Initialize();
    int     Update();
    void    Draw();

    Vector3 Position();
    Vector3 GetFrontVector();
    Vector3 GetUpVector();
    MODEL GetCollision() { return _collision; }
    Boomerang GetBoomerang() { return _boomerang; }
    void SetAnimState(int state) { _animstate = state; }
    bool GetShootState() { return _shootstate; }
    int GetAnimState() { return _animstate; }
    void Shoot();
    void ChangeAnimation();
    int CallOnCollisionEnter();
    void OnCollisionEnter();
    float Power();
    enum AnimationState
    {
        WAIT,
        RUN,
        SHOOT,
        DAMAGE,
        ALLTYPE
    };
private:
    void    Move(KeyboardState);
    Vector3 Angle();
    void    Damage();
    void    LoadCSV();

    Vector3         _position;
    Vector3         _angle;
    float           _power = 0.0f;
    int             _hp = 1;
    int             _animstate = 0;
    int             _oldanimstate = 0;
    float           _animation_count = 0;
    bool            _shootstate = false;
    Boomerang       _boomerang;

    MODEL           _collision;
    ANIMATIONMODEL  _model;

    Vector3 start_position;
    Vector3 end_position;

    Vector3 control_position1;
    Vector3 control_position2;

    int   _callcount;
    int   _invincibletime;
    bool  _invincibleflag;

    bool  _timelagstate;//腕を振りおろしたかどうか

    float _frontdistance;
    float _sidedistance;
    
    float _playermove;

    int _max_invincibletime;
};