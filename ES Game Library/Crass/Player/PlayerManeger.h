#pragma once

#include"../../ESGLib.h"
#include"Boomerang.h"
#include"../LoadCSV/LoadCSV.h"

class PlayerManager {
public:
    PlayerManager::PlayerManager();
    PlayerManager::~PlayerManager();

    bool    Initialize();
    int     Update();
    void    Draw();

    Vector3 GetPosition();
    ANIMATIONMODEL GetModel() { return _model; }
    MODEL GetCollision() { return _collision; }
    Boomerang GetBoomerang() { return _boomerang; }
    bool GetShootState() { return _shootstate; }
    int GetAnimState() { return _animstate; }
    void Shoot();
    void ChangeAnimation();
    void OnCollisionEnter();
    enum AnimationState
    {
        WAIT,
        RUN,
        SHOOT,
        DAMAGE,
        ALLTYPE
    };
    float TestRotationNow();
    float TestRotation90();
private:
    void    KeyboardMove(KeyboardState);
    void    PadMove(GamePadState);
    void    Damage();

    MODEL           _collision;
    ANIMATIONMODEL  _model;

    //!アニメーション
    int             _animstate = 0;
    int             _oldanimstate = 0;
    float           _animation_count = 0;

    //!ブーメラン
    float           _power = 0.0f;
    bool            _shootstate = false;
    Boomerang       _boomerang;

    //!無敵
    int   _invincibletime;
    bool  _invincibleflag;

    //!csvファイルを読み込んでその値を入れる変数
    int   _hp = 1;
    int   _max_invincibletime;
    float _frontdistance;
    float _sidedistance;
    float _playermove;

    //!プレイヤーの挙動
    float   _rotate_direction;
    Vector3 _frontvector;
    float   _rotation;
    float   _atan2_change;

    //!ローテーション確認用
    float _test_rotation_now;
    float _test_rotation_90;

};