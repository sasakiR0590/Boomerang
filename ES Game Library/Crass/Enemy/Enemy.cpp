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

	shape.Width  = 10;
	shape.Height = 10;
	shape.Length = 10;

	Material mtrl;
	mtrl.Diffuse  = Color(0, 0, 0);
	mtrl.Ambient  = Color(0, 0, 0);
	mtrl.Specular = Color(0, 0, 0);

	_collision = GraphicsDevice.CreateModelFromSimpleShape(shape);
	_collision->SetScale(3, 6, 3);
	_collision->SetMaterial(mtrl);
	float rand = MathHelper_Random(-500, 500);
	_position =  Vector3(rand, 0, 300);
	_model->SetPosition(_position);
	_hp = 10;
	return true;
}

int Enemy::Update()
{
	Move();

	_collision->SetPosition(_model->GetPosition() + Vector3(0,20.0f,0));
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
