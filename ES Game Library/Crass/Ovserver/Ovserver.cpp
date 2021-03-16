#include"Ovserver.h"
Ovserver::Ovserver()
{
	_playermanager = new PlayerManager;
	_enemymanager = new EnemyManager;
}

Ovserver::~Ovserver()
{
	delete _enemymanager;
	delete _playermanager;
}

int Ovserver::Update(PlayerManager* playerdata, EnemyManager* enemydata)
{
	_playermanager = playerdata;
	_enemymanager = enemydata;
	auto enemy = _enemymanager->GetEnemy();

	if (_playermanager->GetAnimState() == _playermanager->SHOOT)
	{
		auto a = _playermanager->GetBoomerang()->GetCollision();
		auto a_pos = a->GetPosition();
		auto a_scale = a->GetScale();
		for (int i = 0;i < enemy.size();i++ )
		{
			auto b = enemy[i]->GetCollision();
			auto b_pos = b->GetPosition();
			auto b_scale = b->GetScale();
			//! aとbのボックスの当たり判定
			if (a_pos.x - a_scale.x < b_pos.x + b_scale.x &&
				a_pos.x + a_scale.x > b_pos.x - b_scale.x &&
				a_pos.y - a_scale.y < b_pos.y + b_scale.y &&
				a_pos.y + a_scale.y > b_pos.y - b_scale.y &&
				a_pos.z - a_scale.z < b_pos.z + b_scale.z &&
				a_pos.z + a_scale.z > b_pos.z - b_scale.z)
			{
				_enemymanager->OnCollisionEnter(i);
			}
		}
	}
	return 0;
}

void Ovserver::ColisionDetection()
{
}
