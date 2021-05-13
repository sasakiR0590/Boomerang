#include "EnemyFactory.h"
#include <fstream>

EnemyFactory::EnemyFactory() {
	LoadCSV::Instance().LoadStatus("csvFile/Enemy/EnemyStatus.csv");
	_moveenemy_speed.x = LoadCSV::Instance()._status.at("#“®‚­•ûŒü(XÀ•W)");
	_moveenemy_speed.y = LoadCSV::Instance()._status.at("#“®‚­•ûŒü(YÀ•W)");
	_moveenemy_speed.z = LoadCSV::Instance()._status.at("#“®‚­•ûŒü(ZÀ•W)");
	_moveenemy_hp      = LoadCSV::Instance()._status.at("#“®‚­“G‚ÌHP");

	LoadCSV::Instance().LoadStatus("csvFile/Enemy/StopEnemyStatus.csv");
	_stopenemy_speed.x = LoadCSV::Instance()._status.at("#“®‚­•ûŒü(XÀ•W)");
	_stopenemy_speed.y = LoadCSV::Instance()._status.at("#“®‚­•ûŒü(YÀ•W)");
	_stopenemy_speed.z = LoadCSV::Instance()._status.at("#“®‚­•ûŒü(ZÀ•W)");
	_stopenemy_hp      = LoadCSV::Instance()._status.at("#Ž~‚Ü‚Á‚Ä‚¢‚é“G‚ÌHP");
	_enemytag.push_back("move");
	_enemytag.push_back("stop");
	_enemytag.push_back("homing");
	_enemytag.push_back("dist_homing");
}

EnemyFactory::~EnemyFactory() {

}

EnemyBase* EnemyFactory::Create(string tag, Vector3 _position, PlayerManager* player_manager)
{
	SetSpeed(tag);
	SetHp(tag);
	EnemyBase* enemy_factory = CreateProduct(tag, _position);
	enemy_factory->Initialize(_position,_speed, _hp);
	return enemy_factory;
}

EnemyBase* EnemyFactory::CreateProduct(string tag, Vector3 _position) {
	if (tag == "move")        { return new NormalEnemy; }
	if (tag	== "stop")        { return new StopEnemy; }
	if (tag == "homing")      { return new HomingEnemy; }
	if (tag == "dist_homing") { return new DistHomingEnemy; }
}

Vector3 EnemyFactory::SetSpeed(string tag){
	Vector3 speeds[] = { _moveenemy_speed ,_stopenemy_speed ,_moveenemy_speed ,_moveenemy_speed };
	for (int i = 0; i < _enemytag.size(); i++)
	{
		if (tag == _enemytag[i]){ _speed = speeds[i]; }
	}
	return _speed;
}

int EnemyFactory::SetHp(string tag) {
	if (tag == "move")        { _hp = _moveenemy_hp; }
	if (tag == "stop")        { _hp = _stopenemy_hp; }
	if (tag == "homing")      { _hp = _moveenemy_hp; }
	if (tag == "dist_homing") { _hp = _moveenemy_hp; }

	return _hp;
}