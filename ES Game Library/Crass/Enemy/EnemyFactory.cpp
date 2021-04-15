#include "EnemyFactory.h"
#include <fstream>

EnemyFactory::EnemyFactory() {
	LoadCSV();
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

void EnemyFactory::LoadCSV() {
	std::ifstream moveenemy_infile("csvFile/Enemy/EnemyStatus.csv");
	std::ifstream stopenemy_infile("csvFile/Enemy/StopEnemyStatus.csv");

	std::string filename;
	TCHAR t_filename[256];

	std::string dummy_line;
	char conma;

	//!動く敵のステータス読み込み
	//一行目
	getline(moveenemy_infile, dummy_line);
	//二行目
	getline(moveenemy_infile, dummy_line);
	//三行目
	moveenemy_infile >> _moveenemy_speed.x >> conma >> _moveenemy_speed.y >> conma >> _moveenemy_speed.z >> conma >> _moveenemy_hp;

	//!動かない敵のステータス読み込み
	//一行目
	getline(stopenemy_infile, dummy_line);
	//二行目
	getline(stopenemy_infile, dummy_line);
	//三行目
	stopenemy_infile >> _stopenemy_hp;
}