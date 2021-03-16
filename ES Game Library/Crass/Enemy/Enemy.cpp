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

	SimpleShape shape;
	shape.Type = Shape_Box;

	shape.Width  = 1;
	shape.Height = 1;
	shape.Length = 1;

	Material mtrl;
	mtrl.Diffuse  = Color(0, 0, 0);
	mtrl.Ambient  = Color(0, 0, 0);
	mtrl.Specular = Color(0, 0, 0);

	_collision = GraphicsDevice.CreateModelFromSimpleShape(shape);
	_collision->SetScale(100);
	_collision->SetMaterial(mtrl);
	float rand = MathHelper_Random(-500.0f, 500.0f);
	_position =  Vector3(rand, 0, 300);
	_model->SetPosition(_position);
	_hp = 10;
	return true;
}

int Enemy::Update()
{
	Move();

	if (_position.z <= - 300) {
		return 1;
	}
	

	if (_hp <= 0) {
		return 1;
	}

	_collision->SetPosition(_model->GetPosition() + Vector3(0, 20, 0));
	_position  = _model->GetPosition();
	return 0;
}

void Enemy::Draw()
{
		_model->Draw();
		_collision->Draw();
}

void Enemy::Move() {
		_model->Move(0, 0, -1);
}


