#include"EnemyManeger.h"
#include"EnemyBase.h"

EnemyManeger::EnemyManeger()
{
	_enemy.clear();
}

EnemyManeger::~EnemyManeger()
{
	for (int i = 0; i < _enemy.size() - 1; i++)
	{
		delete _enemy[i];
	}
}

bool EnemyManeger::Initialize()
{

	return true;
}

int EnemyManeger::Update()
{
	time++;
	Generate();
	for (int i = 0; i < _enemy.size() - 1; i++)
	{
		_enemy[i]->Update();
	}
	return 0;
}

void EnemyManeger::Draw()
{
	for (int i = 0; i < _enemy.size() - 1; i++)
	{
		_enemy[i]-> Draw();
	}
}

void EnemyManeger::Generate() {
	if (time >= 100)
	{
		_enemy.push_back(new Enemy);
		_enemy[_enemy.size()]->Initialize();
		time = 0;
	}
}

void EnemyManeger::OnCollisionEnter() {

}