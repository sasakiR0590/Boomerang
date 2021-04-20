#pragma once

#include "../../ESGLib.h"
#include "../LoadCSV/LoadCSV.h"
#include"EnemyBase.h"
#include "StopEnemy.h"
#include"Enemy.h"

class EnemyFactory {
public:
	EnemyFactory::EnemyFactory();
	EnemyFactory::~EnemyFactory();

	EnemyBase* Create(string tag, Vector3 _position);
	EnemyBase* CreateProduct(string tag,Vector3 _position);
	Vector3 SetSpeed(string tag);
	int     SetHp(string tag);
private:
	Vector3 _speed;
	int     _hp;

	//!�����G�L�����̃X�e�[�^�X
	Vector3 _moveenemy_speed;
	int     _moveenemy_hp;

	//!�����Ȃ��G�L�����̃X�e�[�^�X
	Vector3 _stopenemy_speed;
	int     _stopenemy_hp;
};