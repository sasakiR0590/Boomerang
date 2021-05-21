#include"EnemyBase.h"
#include "../../EnemyManeger.h"
#include "../../../Data/MyAlgorithm.h"
EnemyBase::EnemyBase()
{
}

EnemyBase::~EnemyBase()
{
}
bool EnemyBase::Initialize(string _model_name,Vector3 position, Vector3 speed, int hp) {



	_model = GraphicsDevice.CreateAnimationModelFromFile(ConvertStringFileName(_model_name));
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
	_collision->SetScale(0.8);
	_collision->SetMaterial(mtrl);

	_position = position;
	_model->SetPosition(_position);

	_model->SetRotation(Vector3_Zero);

	_hp = hp;
	_speed.z = speed.z;

	player_pos = Vector3_Zero;
	return true;
}

int EnemyBase::Update(PlayerManager* playermanager) {
	IsDamage();
	return 0;
}
void EnemyBase::Draw() {
	_model->Draw();
}

void EnemyBase::Damage() {
	_hp -= 1;
	damage_flag = true;
}

bool EnemyBase::IsDamage() {
	if (damage_flag && damage_frame < DAMAGE_STOP_FRAME) {
		damage_frame++;
		return true;
	}
	else {
		damage_flag = false;
		return false;
	}
}

int EnemyBase::AutoDead()
{
	if (IsDead()) {
		_destroy_time++;
	}
	else {
		return DEATH;
	}
	return LIVING;
}

bool EnemyBase::IsDead()
{
	if (_destroy_time < AUTODEADTIME || time_left < time_over)return true;
	return false;
}


