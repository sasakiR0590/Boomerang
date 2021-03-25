#include"EnemyManeger.h"
#include"EnemyBase.h"
#include <fstream>

EnemyManager::EnemyManager()
{
	_enemy = {};
	
}

EnemyManager::~EnemyManager()
{
	for (int i = 0; i < _enemy.size(); i++)
	{
		delete _enemy[i];
	}
}

bool EnemyManager::Initialize()
{
	_moveenemy_speed = Vector3_Zero;
	_moveenemy_hp    = 0;
	_stopenemy_speed = Vector3_Zero;
	_stopenemy_hp    = 0;
	LoadCSV();
	return true;
}

int EnemyManager::Update()
{
	_time++;
	Generate();

	for (int i = 0; i < _enemy.size(); i++)
	{
		//敵が倒されたとき
		if (_enemy[i]->Update() == 1)
		{
			_enemy.erase(_enemy.begin() + i);
		}
	}
	return 0;
}

void EnemyManager::Draw()
{
	for (int i = 0; i < _enemy.size(); i++)
	{
		 _enemy[i]-> Draw();
	}
}

void EnemyManager::Generate()
{
	if (_time >= 500)
	{
		_enemy.push_back(new Enemy);
		_enemy[_enemy.size() - 1]->Initialize(_moveenemy_speed, _moveenemy_hp);

		_enemy.push_back(new StopEnemy);
		_enemy[_enemy.size() - 1]->Initialize(_stopenemy_speed, _stopenemy_hp);
		_time = 0;
	}
}

void EnemyManager::OnCollisionEnter(int num)
{
	_enemy[num]->Damage();
}

void EnemyManager::LoadCSV()
{
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