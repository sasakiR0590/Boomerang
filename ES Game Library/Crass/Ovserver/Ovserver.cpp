#include"Ovserver.h"
Ovserver::Ovserver()
{
}

Ovserver::~Ovserver()
{
}

int Ovserver::Update()
{
 	PlayerManeger* playermanager = new PlayerManeger;
	EnemyManeger*  enemymanager = new EnemyManeger;
	auto enemy = enemymanager->GetEnemy();

	if (playermanager->GetAnimState() == playermanager->SHOOT)
	{
		auto a = playermanager->GetBoomerang()->GetCollision();
		auto a_pos = a->GetPosition();
		auto a_scale = a->GetScale();
		for (int i = 0;i > enemy.size();i++ )
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
				enemymanager->OnCollisionEnter(i);
			}
		}
	}

	delete enemymanager;
	delete playermanager;
	return 0;
}

void Ovserver::ColisionDetection()
{
}
