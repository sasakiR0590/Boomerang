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
    int AttackPattern();
    Vector3 PlayerGetPosition();
    enum AnimationState
    {
        WAIT,
        RUN,
        SHOOT,
        DAMAGE,
        ALLTYPE
    };
private:
    void    KeyboardMove(KeyboardState);
    void    PadMove(GamePadState);
    void    Damage();

    void    ChangeAttackPattern();
    void    BoomerangSizeUp();
    void    BoomerangSpeedUp();
    void    BoomerangDistanceUp();

    MODEL           _collision;
    ANIMATIONMODEL  _model;

    //!�A�j���[�V����
    int             _animstate = 0;
    int             _oldanimstate = 0;
    float           _animation_count = 0;

    //!�u�[������
    float           _power = 0.0f;
    bool            _shootstate = false;
    Boomerang       _boomerang;

    //!���G
    int   _invincibletime;
    bool  _invincibleflag;

    //!csv�t�@�C����ǂݍ���ł��̒l������ϐ�
    int   _hp = 1;
    int   _max_invincibletime;
    float _frontdistance;
    float _sidedistance;
    float _playermove;

    Vector3 _player_position;

    //!�v���C���[�̋���
    float   _rotate_direction;
    Vector3 _frontvector;
    float   _rotation;
    float   _atan2_change;

    //!�u�[�������̐�����؂�ւ���
    int _attack_pattern;

    //!�u�[�������̐����ω��p�̐��l������
    float _boomerang_addspeed;
    float _boomerang_adddistance;
};