#include"HomingEnemy.h"
#include"../EnemyBase/EnemyBase.h"

HomingEnemy::HomingEnemy()
{
}

HomingEnemy::~HomingEnemy()
{
}

bool HomingEnemy::Initialize(Vector3 position, Vector3 speed, int hp)
{
	_model		= GraphicsDevice.CreateAnimationModelFromFile(_T("MODEL/Enemy/enemy_White.X"));
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
	return true;
}

int HomingEnemy::Update()
{
	player_pos = pm.PlayerGetPosition();

	Move();
	_animestate = ANIMESTATE::RUN;

	if (_position.z <= - 8.8f) {
		return EnemyManager::DEATH;
	}
	

	if (_hp <= 0) {
		return EnemyManager::DEATH;
	}


	_collision->SetPosition(_model->GetPosition() + Vector3(0, 0, 0));
	_position  = _model->GetPosition();

	return EnemyManager::LIVING;
}

void HomingEnemy::Draw()
{
	ChangeAnimation();
	_model->Draw();
	//_collision->Draw();
}

void HomingEnemy::Move() {

	_model->Move(0, 0, -_speed.z);
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