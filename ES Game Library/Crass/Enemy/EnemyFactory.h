#pragma once

#include "../../ESGLib.h"
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
	void LoadCSV();

	Vector3 _speed;
	int     _hp;

	//!動く敵キャラのステータス
	Vector3 _moveenemy_speed;
	int     _moveenemy_hp;

	//!動かない敵キャラのステータス
	Vector3 _stopenemy_speed;
	int     _stopenemy_hp;
};