#include"HomingEnemy.h"

HomingEnemy::HomingEnemy()
{
}

HomingEnemy::~HomingEnemy()
{
}

bool HomingEnemy::Initialize(Vector3 position, Vector3 speed, int hp)
{
	_model		= GraphicsDevice.CreateAnimationModelFromFile(_T("MODEL/Enemies/HomingEnemy/enemy_Eye.X"));

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

int HomingEnemy::Update(PlayerManager* player_manager)
{
	float floor_area_x = _position.x > 8.5f || _position.x < -8.5f;
	float floor_area_z = _position.z < -8.5f;

	player_pos = player_manager->PlayerGetPosition();

	Move();
	Rotate();

	_animestate = ANIMESTATE::RUN;

	if (destroy_time < 960)
		destroy_time++;

	if (_hp <= 0 || floor_area_x || floor_area_z || destroy_time > 960) {
		destroy_time = 0;
		return EnemyBase::DEATH;
	}


	_collision->SetPosition(_model->GetPosition() + Vector3(0, 0, 0));
	_position  = _model->GetPosition();

	return EnemyBase::LIVING;
}

void HomingEnemy::Draw()
{
	ChangeAnimation();
	_model->Draw();
	//_collision->Draw();
}

void HomingEnemy::Move() {
	Vector3 delta  = Vector3_Normalize(Vector3(_position - player_pos));
	float speed = 30;

	if(_position.z > player_pos.z)
		_model->Move(0,0, -delta.z / speed);
	else
		_model->Move(0, 0, delta.z / speed);

}

void HomingEnemy::Rotate() {
	_rotation = MathHelper_Atan2((player_pos.z - _position.z), -(player_pos.x - _position.x)) + 90.0f;
	_model->SetRotation(0.0f, _rotation, 0.0f);
}

void HomingEnemy::ChangeAnimation() {
	auto index = _oldanimestate;

	_animation_count += GameTimer.GetElapsedSecond() * 2;

	//全てのアニメーションの停止
	for (int i = 0; i < ANIMESTATE::ALLTYPE; ++i) {
		_model->SetTrackEnable(i, FALSE);
	}

	//アニメーションの状態が地がければ更新
	if (_animestate != index) {
		_oldanimestate = _animestate;
		_animation_count = 0;
	}

	//アニメーションの再生
	_model->SetTrackEnable(_animestate, TRUE);
	_model->SetTrackPosition(_animestate, _animation_count);
}