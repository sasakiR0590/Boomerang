#include"Enemy.h"
#include"EnemyBase.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

bool Enemy::Initialize(Vector3 speed, int hp)
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
	float rand = MathHelper_Random(-7.0f, 7.0f);
	_position =  Vector3(rand, 0, 5);
	_model->SetPosition(_position);
	_model->SetRotation(0, 180, 0);
	_hp = hp;
	_speed.z = speed.z;
	return true;
}

int Enemy::Update()
{
	Move();
	_animestate = ANIMESTATE::RUN;

	if (_position.z <= - 6.0f) {
		return EnemyManager::DEATH;
	}
	

	if (_hp <= 0) {
		return EnemyManager::DEATH;
	}


	_collision->SetPosition(_model->GetPosition() + Vector3(0, 0, 0));
	_position  = _model->GetPosition();

	return EnemyManager::LIVING;
}

void Enemy::Draw()
{
	ChangeAnimation();
	_model->Draw();
	_collision->Draw();
}

void Enemy::Move() {
	_model->Move(0, 0, _speed.z);
}

void Enemy::ChangeAnimation() {
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