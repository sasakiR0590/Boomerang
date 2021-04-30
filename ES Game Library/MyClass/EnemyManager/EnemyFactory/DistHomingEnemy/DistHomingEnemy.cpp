#include"DistHomingEnemy.h"
#include"../../EnemyManeger.h"
DistHomingEnemy::DistHomingEnemy()
{
}

DistHomingEnemy::~DistHomingEnemy()
{
}

bool DistHomingEnemy::Initialize(Vector3 position, Vector3 speed, int hp)
{
	_model		= GraphicsDevice.CreateAnimationModelFromFile(_T("MODEL/Enemies/DistHomingEnemy/enemy_c3.X"));

	SimpleShape shape;
	shape.Type = Shape_Box;

	shape.Width  = 1;
	shape.Height = 1;
	shape.Length = 1;

	Material mtrl;
	mtrl.Diffuse  = Color(1.0f, 1.0f, 1.0f);
	mtrl.Ambient  = Color(1.0f, 1.0f, 1.0f);
	mtrl.Specular = Color(1.0f, 1.0f, 1.0f);

	_collision = GraphicsDevice.CreateModelFromSimpleShape(shape);
	_collision->SetScale(1);
	_collision->SetMaterial(mtrl);
	_position = position;
	_model->SetPosition(_position);

	_hp = hp;
	_speed.z = speed.z;

	player_pos = Vector3_Zero;
	return true;
}

int DistHomingEnemy::Update(PlayerManager* player_manager)
{
	 float floor_area_x = _position.x > 8.5f || _position.x < -8.5f;
	 float floor_area_z = _position.z < -8.5f;

	player_pos = player_manager->PlayerGetPosition();
	Move();

	_animestate = ANIMESTATE::RUN;

	float dist = Vector3_Distance(player_pos, Vector3(_position.x,0,_position.z));
	if (dist <= 7.0f) {
		homing_flag = true;
	}
	else
		homing_flag = false;

	if (destroy_time < 960)
		destroy_time++;

	if (_hp <= 0 || floor_area_x  || floor_area_z || destroy_time > 960) {
		destroy_time = 0;
		return EnemyManager::DEATH;
	}


	_collision->SetPosition(_model->GetPosition() + Vector3(0, 0, 0));
	_position  = _model->GetPosition();
	return EnemyManager::LIVING;
}

void DistHomingEnemy::Draw()
{
	ChangeAnimation();
	_model->Draw();
	//_collision->Draw();
}

void DistHomingEnemy::Move() {
	if (homing_flag) {
		Vector3 delta = Vector3_Normalize(Vector3(_position - player_pos));
		float speed = 40;

		_model->Move(-delta.x / speed, 0, -delta.z / speed);
	}
	else
		_model->Move(0, 0, -_speed.z / 4);
}

void DistHomingEnemy::ChangeAnimation() {
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