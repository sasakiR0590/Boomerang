#include"Enemy.h"
#include"EnemyBase.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

bool Enemy::Initialize()
{
	_model		= GraphicsDevice.CreateModelFromFile(_T("kariMan_1.X"));
//	_collision  = 
	_position =  Vector3(0, 0, 1);
	_angle	  =  Vector3(0, 0, 0);
	_model->SetPosition(_position);
	_model->SetRotation(_angle);
	_hp = 10;
	return true;
}

int Enemy::Update()
{
	Move();
	return 0;
}

void Enemy::Draw()
{
	_model->Draw();
}

void Enemy::Move() {
	_position.z -= 0.5f;
}
