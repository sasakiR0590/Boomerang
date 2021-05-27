#include"HomingEnemy.h"

HomingEnemy::HomingEnemy()
{
}

HomingEnemy::~HomingEnemy()
{
}
int HomingEnemy::Update(PlayerManager* player_manager)
{
	float floor_area_x = _position.x >  _homing_area || _position.x < -_homing_area;
	float floor_area_z = _position.z < -_homing_area;

	player_pos = player_manager->PlayerGetPosition();

	if (!EnemyBase::IsDamage()) {
		Move();
		Rotate();
	}

	_animestate = ANIMESTATE::RUN;

	if (_hp <= 0)
		return EnemyBase::DEATH;

	if (floor_area_x || floor_area_z)
		return EnemyBase::DESTROY;

	_collision->SetPosition(_model->GetPosition());
	_position  = _model->GetPosition();

	return EnemyBase::LIVING;
}

void HomingEnemy::Draw()
{
	ChangeAnimation();
}

void HomingEnemy::Move() {
	Vector3 delta  = Vector3_Normalize(Vector3(_position - player_pos));
	float speed_index = 0.015f;
	float move_speed = delta.z * speed_index;

	if (_position.z > player_pos.z)
		_model->Move(0, 0, - move_speed);
	else
		_model->Move(0, 0,   move_speed);

}

void HomingEnemy::Rotate() {
	_rotation = MathHelper_Atan2((player_pos.z - _position.z), -(player_pos.x - _position.x)) + 90.0f;
	_model->SetRotation(0.0f, _rotation, 0.0f);
}

void HomingEnemy::ChangeAnimation() {
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