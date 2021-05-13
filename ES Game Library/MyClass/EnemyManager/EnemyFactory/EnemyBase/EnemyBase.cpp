#include"EnemyBase.h"
#include "../../EnemyManeger.h"

EnemyBase::EnemyBase()
{
}

EnemyBase::~EnemyBase()
{
}
bool EnemyBase::Initialize(Vector3 position, Vector3 speed, int hp) {
	return true;
}

int EnemyBase::Update(PlayerManager* playermanager) {
	IsDamage();
	return 0;
}

void EnemyBase::Damage() {
	_hp -= 1;
	damage_flag = true;
}

bool EnemyBase::IsDamage() {
	if (damage_flag && damage_frame < DAMAGE_STOP_FRAME) {
		damage_frame++;
		return true;
	}
	else {
		damage_flag = false;
		return false;
	}
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


