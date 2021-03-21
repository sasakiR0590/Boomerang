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
    int GetAnimState() { return _animstate; }
    void Shoot();
    int CallOnCollisionEnter();
    void OnCollisionEnter();
    enum AnimationState
    {
        WAIT,
        RUN,
        SHOOT,
        DAMAGE
    };
private:
    void Move(KeyboardState);
    Vector3 Angle();
    int     Power();
    void    Damage();

    Vector3    _position;
    Vector3    _angle;
    int        _power;
    int        _hp;
    int        _animstate = 0;
    Boomerang _boomerang;

    MODEL      _collision;
    MODEL      _model;

    Vector3 start_position;
    Vector3 end_position;

    int   _callcount;
    int   _invincibletime;
    bool  _invincibleflag;
};