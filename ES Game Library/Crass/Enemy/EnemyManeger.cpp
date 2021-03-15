#include"EnemyManeger.h"
#include"EnemyBase.h"

EnemyManeger::EnemyManeger()
{
	_enemy = {};
}

EnemyManeger::~EnemyManeger()
{
	//for (int i = 0; i < _enemy.size(); i++)
	//{
	//	delete _enemy[i];
	//}
}

bool EnemyManeger::Initialize()
{
	return true;
}

int EnemyManeger::Update()
{
	time++;
	Generate();

	for (int i = 0; i < _enemy.size(); i++)
	{
		//“G‚ª“|‚³‚ê‚½‚Æ‚«
		if (_enemy[i]->Update() == 1)
		{
			_enemy.erase(_enemy.begin() + i);
		}
	}
	return 0;
}

void EnemyManeger::Draw()
{
	for (int i = 0; i < _enemy.size(); i++)
	{
		 _enemy[i]-> Draw();
	}
}

void EnemyManeger::Generate() {
	if (time >= 500)
	{
		_enemy.push_back(new Enemy);
		_enemy[_enemy.size() - 1]->Initialize();

		_enemy.push_back(new StopEnemy);
		_enemy[_enemy.size() - 1]->Initialize();
		time = 0;
	}
}

void EnemyManeger::OnCollisionEnter(int num) {
	_enemy.erase(_enemy.begin() + num);
}