#include"StopEnemy.h"
#include"EnemyBase.h"

StopEnemy::StopEnemy()
{
}

StopEnemy::~StopEnemy()
{
}

bool StopEnemy::Initialize(Vector3 speed, int hp)
{
	_model		= GraphicsDevice.CreateAnimationModelFromFile(_T("MODEL/Enemy/Enemy_animetion_0329.X"));

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
	_collision->SetScale(1);
	_collision->SetMaterial(mtrl);
	float random_x = MathHelper_Random(-7.0f, 7.0f);
	float random_z = MathHelper_Random(-6.0f, 5.0f);
	_position =  Vector3(random_x, 0, random_z);
	_model->SetPosition(_position);
	_model->SetRotation(0, 180, 0);
	_hp = hp;
	return true;
}

int StopEnemy::Update()
{
	_animestate = ANIMESTATE::WAIT;

	if (destroy_time < 960) {
		destroy_time++;
	}
	else {
		destroy_time = 0;
		return EnemyManager::DEATH;
	}

	if (_hp <= 0) {
		return EnemyManager::DEATH;
	}

	_collision->SetPosition(_model->GetPosition() + Vector3(0, 0, 0));
	_position = _model->GetPosition();

	return EnemyManager::LIVING;
}

void StopEnemy::Draw()
{
	ChangeAnimation();
	_model->Draw();
	_collision->Draw();
}

void StopEnemy::ChangeAnimation() {
	auto index = _oldanimestate;

	_animation_count += GameTimer.GetElapsedSecond() * 2;

	for (int i = 0; i < ANIMESTATE::ALLTYPE; ++i) {
		_model->SetTrackEnable(i, FALSE);
	}

	if (_animestate != index) {
		_oldanimestate = _animestate;
		_animation_count = 0;
	}

	_model->SetTrackEnable(_animestate, TRUE);
	_model->SetTrackPosition(_animestate, _animation_count);

}

