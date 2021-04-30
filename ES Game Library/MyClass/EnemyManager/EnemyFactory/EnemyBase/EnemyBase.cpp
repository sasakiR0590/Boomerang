#include"EnemyBase.h"
#include "../../EnemyManeger.h"

EnemyBase::EnemyBase()
{
}

EnemyBase::~EnemyBase()
{
}

int EnemyBase::Update(PlayerManager* playermanager) {
	return 0;
}

void EnemyBase::Damage() {
	_hp -= 1;
}

int EnemyBase::AutoDead()
{
	if (IsDead()) {
		_destroy_time++;
	}
	else {
		return DEATH;
	}
	return LIVING;
}

bool EnemyBase::IsDead()
{
	if (_destroy_time < AUTODEADTIME)return true;
	return false;
}


