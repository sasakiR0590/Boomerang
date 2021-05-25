#include"NormalEnemy.h"

NormalEnemy::NormalEnemy() {

}
NormalEnemy::~NormalEnemy() {

}

int NormalEnemy::Update(PlayerManager* player_manager)
{
	if (!EnemyBase::IsDamage())
		Move();

	_animestate = ANIMESTATE::RUN;

	if (_hp <= 0)
		return EnemyBase::DEATH;

	if (_position.z <= enemy_living_area_z)
		return EnemyBase::DESTROY;

	_collision->SetPosition(_model->GetPosition());
	_position  = _model->GetPosition();

	return EnemyBase::LIVING;
}

void NormalEnemy::Draw()
{
	ChangeAnimation();
	_model->Draw();
	//_collision->Draw();
}

void NormalEnemy::Move() {
	_model->Move(0, 0, -_speed.z);
}

void NormalEnemy::ChangeAnimation() {
	auto index = _oldanimestate;

	_animation_count += GameTimer.GetElapsedSecond() * 2.0;

	//�S�ẴA�j���[�V�����̒�~
	for (int i = 0; i < ANIMESTATE::ALLTYPE; ++i) {
		_model->SetTrackEnable(i, FALSE);
	}

	//�A�j���[�V�����̏�Ԃ��n������΍X�V
	if (_animestate != index) {
		_oldanimestate = _animestate;
		_animation_count = 0;
	}

	//�A�j���[�V�����̍Đ�
	_model->SetTrackEnable(_animestate, TRUE);
	_model->SetTrackPosition(_animestate, _animation_count);
}