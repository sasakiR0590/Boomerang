#pragma once

#include "../../LoadCSV/LoadCSV.h"
#include "EnemyBase/EnemyBase.h"
#include "StopEnemy/StopEnemy.h"
#include "NomalEnemy/NormalEnemy.h"
#include "HomingEnemy/HomingEnemy.h"
#include "DistHomingEnemy/DistHomingEnemy.h"

class EnemyFactory {
public:
	EnemyFactory::EnemyFactory();
	EnemyFactory::~EnemyFactory();

	EnemyBase* Create(string tag, Vector3 _position, PlayerManager* player_manager);
	EnemyBase* CreateProduct(string tag,Vector3 _position);
	string SetModel(string tag);
	Vector3 SetSpeed(string tag);
	int     SetHp(string tag);
private:
	string  _model_name;
	Vector3 _speed;
	int     _hp;
	EnemyBase* _enemy;

	//!動く敵キャラのステータス
	Vector3 _moveenemy_speed;
	int     _moveenemy_hp;

	//!動かない敵キャラのステータス
	Vector3 _stopenemy_speed;
	int     _stopenemy_hp;

	std::vector<string> _enemytag;
	string _enemy_model[4];

	enum EnemyType {MOVE,STOP,HOMING,DIST_HOMING};
};