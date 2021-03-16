#include"EnemyManeger.h"
#include"EnemyBase.h"

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
	return true;
}

int EnemyManager::Update()
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

void EnemyManager::Draw()
{
	for (int i = 0; i < _enemy.size(); i++)
	{
		 _enemy[i]-> Draw();
	}
}

void EnemyManager::Generate() {
	if (time >= 500)
	{
		_enemy.push_back(new Enemy);
		_enemy[_enemy.size() - 1]->Initialize();

		_enemy.push_back(new StopEnemy);
		_enemy[_enemy.size() - 1]->Initialize();
		time = 0;
	}
}

void EnemyManager::OnCollisionEnter(int num) {
	_enemy.erase(_enemy.begin() + num);
}