#pragma once

#include"Boomerang/Boomerang.h"
#include"../LoadCSV/LoadCSV.h"

class PlayerManager {
public:
    PlayerManager::PlayerManager();
    PlayerManager::~PlayerManager();

    bool    Initialize();
    int     Update();
    void    Draw();

    ANIMATIONMODEL GetModel() { return _model; }
    MODEL GetCollision() { return _collision; }
    Boomerang GetBoomerang() { return _boomerang; }
    bool GetShootState() { return _shootstate; }
    int GetAnimState() { return _animstate; }
    void Shoot();
    void ChangeAnimation();
    void OnCollisionEnter();
    Vector3 PlayerGetPosition();
    enum AnimationState
    {
        WAIT,
        RUN,
        SHOOT,
        STANCE,
        DAMAGE,
        ALLTYPE
    };
#ifdef _DEBUG
    int AttackPattern();
    void    ChangeAttackPattern();
    void    BoomerangSizeUp();
    void    BoomerangSpeedUp();
    void    BoomerangDistanceUp();
#endif
private:
    void    KeyboardMove(KeyboardState);
    void    PadMove(GamePadState);
    void    Damage();

    void    FlyPoint();
    void    MovePlayerRotate(GamePadState);
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

    Vector3 _player_position;

    //!プレイヤーの挙動
    float   _rotate_direction;
    Vector3 _frontvector;
    float   _rotation;
    float   _atan2_change;

    //!ブーメランの性質を切り替える
    int _attack_pattern;

    //!ブーメランの性質変化用の数値を入れる
    float _boomerang_addspeed;
    float _boomerang_adddistance;

    std::vector<Vector3> padstick;
};