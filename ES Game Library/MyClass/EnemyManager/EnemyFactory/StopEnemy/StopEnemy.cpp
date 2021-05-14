#include"StopEnemy.h"
StopEnemy::StopEnemy()
{
}

StopEnemy::~StopEnemy()
{
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

