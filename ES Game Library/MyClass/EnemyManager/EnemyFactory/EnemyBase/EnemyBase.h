#pragma once

/**
 * @file   EnemyBase.h
 * @brief  �G�̌��ɂȂ�N���X
 * @author Mitsuhide Kowata
 * @date �@2021/03/31
 */

#include "../../../../ESGLib.h"
#include"../../../PlayerManager/PlayerManeger.h"
#include "../../../TimeManager/TimeManager.h"
#include "../../../SceneManager/SceneManager.h"

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
    bool IsDamage();
    Vector3 _position;
    Vector3 _angle;
    Vector3 _speed;
    Vector3 player_pos;
    int     _hp;
    MODEL   _collision;
    ANIMATIONMODEL   _model;

    float   _rotation = 0.0f;
    const float  _homing_area = 8.5f;

   /**
    * @enum EnemyState
    * �G�̏��
    */
    enum EnemyState{ LIVING,DESTROY, DEATH };
private:
    /**
     * @enum Frame
     * �G�Ɋ֌W���鎞�Ԍv���p
     */
    enum Frame { 
        //!�_���[�W���󂯂��G���~�܂鎞��
        DAMAGE_STOP_FRAME = 30, 
        //!�G�������폜����鎞��
        AUTODEADTIME = 900 
    };
    enum Dist_Enemy {
        REMAINDER = 0,
        DIST_ENEMY_NUM = 10
    };

    int  PlusHp();
    bool IsDead();
    bool LimitDestruction();
    int _destroy_time = 0;
    bool  damage_flag = false;
    float damage_frame = 0.0f;

    const float time_over = 0.9f;

    int _add_damage = 0;
    int _combo = 0;
};