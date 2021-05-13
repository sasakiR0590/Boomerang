#include"StopEnemy.h"
StopEnemy::StopEnemy()
{
}

StopEnemy::~StopEnemy()
{
}

bool StopEnemy::Initialize(Vector3 position, Vector3 speed, int hp)
{
	_model = GraphicsDevice.CreateAnimationModelFromFile(_T("MODEL/Enemies/StopEnemy/enemy_round.X"));

	SimpleShape shape;
	shape.Type = Shape_Box;

	shape.Width = 1;
	shape.Height = 1;
	shape.Length = 1;

	Material mtrl;
	mtrl.Diffuse = Color(1.0f, 1.0f, 1.0f);
	mtrl.Ambient = Color(1.0f, 1.0f, 1.0f);
	mtrl.Specular = Color(1.0f, 1.0f, 1.0f);

	_collision = GraphicsDevice.CreateModelFromSimpleShape(shape);
	_collision->SetScale(1);
	_collision->SetMaterial(mtrl);
	_position = position;
	_model->SetPosition(_position);
	_model->SetRotation(Vector3_Zero);

	_hp = hp;
	_speed.z = speed.z;

	player_pos = Vector3_Zero;
	return true;
}

int StopEnemy::Update(PlayerManager* player_manager)
{
	_animestate = ANIMESTATE::WAIT;

	if (_hp <= 0) {
		return EnemyBase::DEATH;
	}

	_collision->SetPosition(_model->GetPosition() + Vector3(0, 0, 0));
	_position = _model->GetPosition();

	return EnemyBase::LIVING;
}

void StopEnemy::Draw()
{
	ChangeAnimation();
	_model->Draw();
	//_collision->Draw();
}

void StopEnemy::ChangeAnimation() {
	auto index = _oldanimestate;

	_animation_count += GameTimer.GetElapsedSecond() * 2.0;

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

