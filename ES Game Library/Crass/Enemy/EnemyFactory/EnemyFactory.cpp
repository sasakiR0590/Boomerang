#include "../EnemyFactory/EnemyFactory.h"
#include <fstream>

EnemyFactory::EnemyFactory() {
	LoadCSV::Instance().LoadStatus("csvFile/Enemy/EnemyStatus.csv");
	_moveenemy_speed.x = LoadCSV::Instance()._status.at("#動く方向(X座標)");
	_moveenemy_speed.y = LoadCSV::Instance()._status.at("#動く方向(Y座標)");
	_moveenemy_speed.z = LoadCSV::Instance()._status.at("#動く方向(Z座標)");
	_moveenemy_hp      = LoadCSV::Instance()._status.at("#動く敵のHP");

	LoadCSV::Instance().LoadStatus("csvFile/Enemy/StopEnemyStatus.csv");
	_stopenemy_speed.x = LoadCSV::Instance()._status.at("#動く方向(X座標)");
	_stopenemy_speed.y = LoadCSV::Instance()._status.at("#動く方向(Y座標)");
	_stopenemy_speed.z = LoadCSV::Instance()._status.at("#動く方向(Z座標)");
	_stopenemy_hp      = LoadCSV::Instance()._status.at("#止まっている敵のHP");
}

EnemyFactory::~EnemyFactory() {

}

EnemyBase* EnemyFactory::Create(string tag, Vector3 _position)
{
	SetSpeed(tag);
	SetHp(tag);
	EnemyBase* enemy_factory = CreateProduct(tag, _position);
	enemy_factory->Initialize(_position,_speed, _hp);
	return enemy_factory;
}

EnemyBase* EnemyFactory::CreateProduct(string tag, Vector3 _position) {
	if (tag == "move_enemy")        { return new Enemy; }
	if (tag	== "stop_enemy")        { return new StopEnemy; }
	if (tag == "homing_enemy")      { return new HomingEnemy; }
	if (tag == "dist_homing_enemy") { return new DistHomingEnemy; }
}

Vector3 EnemyFactory::SetSpeed(string tag){
	if (tag == "move_enemy")        { _speed = _moveenemy_speed; }
	if (tag == "stop_enemy")        { _speed = _stopenemy_speed; }
	if (tag == "homing_enemy")      { _speed = _moveenemy_speed; }
	if (tag == "dist_homing_enemy") { _speed = _moveenemy_speed; }

	return _speed;
}

int EnemyFactory::SetHp(string tag) {
	if (tag == "move_enemy")        { _hp = _moveenemy_hp; }
	if (tag == "stop_enemy")        { _hp = _stopenemy_hp; }
	if (tag == "homing_enemy")      { _hp = _moveenemy_hp; }
	if (tag == "dist_homing_enemy") { _hp = _moveenemy_hp; }

	return _hp;
}