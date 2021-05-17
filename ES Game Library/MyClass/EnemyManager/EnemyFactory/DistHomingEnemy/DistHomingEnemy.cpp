#include"DistHomingEnemy.h"
#include"../../EnemyManeger.h"
DistHomingEnemy::DistHomingEnemy()
{
}

DistHomingEnemy::~DistHomingEnemy()
{
}

int DistHomingEnemy::Update(PlayerManager* player_manager)
{
	 float floor_area_x = _position.x >  _homing_area || _position.x < -_homing_area;
	 float floor_area_z = _position.z < -_homing_area;

	player_pos = player_manager->PlayerGetPosition();

	if (!EnemyBase::IsDamage()) {
		Move();
		Rotate();
	}

	_animestate = ANIMESTATE::RUN;

	float dist = Vector3_Distance(player_pos, Vector3(_position.x,0,_position.z));
	if (dist <= 7.0f) {
		homing_flag = true;
	}
	else
		homing_flag = false;

	if (_hp <= 0 || floor_area_x  || floor_area_z) {
		return EnemyBase::DEATH;
	}


	_collision->SetPosition(_model->GetPosition() + Vector3(0, 0, 0));
	_position  = _model->GetPosition();
	return EnemyBase::LIVING;
}

void DistHomingEnemy::Draw()
{
	ChangeAnimation();
}

void DistHomingEnemy::Move() {
	if (homing_flag) {
		Vector3 delta = Vector3_Normalize(Vector3(_position - player_pos));
		float speed = 30;

		if(_position.z > player_pos.z)
			_model->Move(0, 0,   delta.z / speed);
		else
			_model->Move(0, 0, - delta.z / speed);
	}
	else
		_model->Move(0, 0,_speed.z / 4);
	    _model->Rotation(Vector3_Zero);
}

void DistHomingEnemy::Rotate() {
	//�v���C���[�̍��W - �G�̍��W�Ńv���C���[�̂�������Ɍ���
	_rotation = MathHelper_Atan2(-(player_pos.z - _position.z), (player_pos.x - _position.x)) + 90.0f;
	_model->SetRotation(0.0f, _rotation, 0.0f);
}

void DistHomingEnemy::ChangeAnimation() {
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