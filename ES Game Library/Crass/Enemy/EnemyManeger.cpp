#include"EnemyManeger.h"
#include"EnemyBase.h"
#include <fstream>

EnemyManager::EnemyManager()
{
	_enemy = {};
	
}

EnemyManager::~EnemyManager()
{
	//範囲for文
	for (auto& enemy : _enemy) {
		 delete enemy;
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

	auto itr = _enemy.begin();
	while (itr != _enemy.end()) {

		//Updateでreturnされた値 0・・生きてる 1・・消去
			if ((*itr)->Update() == LIVING)
				itr++;
			else
				//要素数が 1 なら消去
				//itrの値を変更して値を一つ進める
				itr = _enemy.erase(itr);
	}
	return 0;
}

void EnemyManager::Draw()
{
	for (auto& enemy : _enemy) {
		enemy->Draw();
	}
}

void EnemyManager::Generate()
{
	if (_time >= 500)
	{
		_enemy.push_back(new Enemy);
		_enemy.back()->Initialize(_moveenemy_speed, _moveenemy_hp);

		_enemy.push_back(new StopEnemy);
		_enemy.back()->Initialize(_stopenemy_speed, _stopenemy_hp);
		_time = 0;
	}
}

void EnemyManager::OnCollisionEnter(EnemyBase* enemy)
{
	enemy->Damage();
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