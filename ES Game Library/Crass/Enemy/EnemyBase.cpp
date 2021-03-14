#include"EnemyBase.h"
EnemyBase::EnemyBase()
{
}

EnemyBase::~EnemyBase()
{
}

int EnemyBase::Update() {
	return 0;
}

void EnemyBase::Damage() {
	_hp -= 1;
}


