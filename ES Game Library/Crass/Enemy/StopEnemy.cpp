#include"StopEnemy.h"
#include"EnemyBase.h"

StopEnemy::StopEnemy()
{
}

StopEnemy::~StopEnemy()
{
}

bool StopEnemy::Initialize()
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
	float random_x = MathHelper_Random(-500.0f, 500.0f);
	float random_z = MathHelper_Random(-500.0f, 500.0f);
	_position =  Vector3(random_x, 0, random_z);
	_model->SetPosition(_position);
	_hp = 10;
	return true;
}

int StopEnemy::Update()
{
	if (destroy_time < 960) {
		destroy_time++;
	}
	else {
		destroy_time = 0;
		return 1;
	}

	if (_hp <= 0) {
		return 1;
	}

	_collision->SetPosition(_model->GetPosition() + Vector3(0,20.0f,0));
	_position = _model->GetPosition();
	return 0;
}

void StopEnemy::Draw()
{
	_model->Draw();
	_collision->Draw();
}

