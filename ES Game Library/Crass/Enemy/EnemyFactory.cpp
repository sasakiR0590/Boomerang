#include "EnemyFactory.h"
#include <fstream>

EnemyFactory::EnemyFactory() {
	LoadCSV::Instance().LoadStatus("csvFile/Enemy/EnemyStatus.csv");
	_moveenemy_speed.x = LoadCSV::Instance()._status.at("#“®‚­•ûŒü(XÀ•W)");
	_moveenemy_speed.y = LoadCSV::Instance()._status.at("#“®‚­•ûŒü(YÀ•W)");
	_moveenemy_speed.z = LoadCSV::Instance()._status.at("#“®‚­•ûŒü(ZÀ•W)");
	_moveenemy_hp = LoadCSV::Instance()._status.at("#“®‚­“G‚ÌHP");

	LoadCSV::Instance().LoadStatus("csvFile/Enemy/StopEnemyStatus.csv");
	_stopenemy_speed.x = LoadCSV::Instance()._status.at("#“®‚­•ûŒü(XÀ•W)");
	_stopenemy_speed.y = LoadCSV::Instance()._status.at("#“®‚­•ûŒü(YÀ•W)");
	_stopenemy_speed.z = LoadCSV::Instance()._status.at("#“®‚­•ûŒü(ZÀ•W)");
	_stopenemy_hp = LoadCSV::Instance()._status.at("#Ž~‚Ü‚Á‚Ä‚¢‚é“G‚ÌHP");
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
	if (tag == "move_enemy") { return new Enemy; }
	if (tag	== "stop_enemy") { return new StopEnemy; }
}

Vector3 EnemyFactory::SetSpeed(string tag){
	if (tag == "move_enemy") { _speed = _moveenemy_speed; }
	if (tag == "stop_enemy") { _speed = _stopenemy_speed; }

	return _speed;
}

int EnemyFactory::SetHp(string tag) {
	if (tag == "move_enemy") { _hp = _moveenemy_hp; }
	if (tag == "stop_enemy") { _hp = _stopenemy_hp; }

	return _hp;
}