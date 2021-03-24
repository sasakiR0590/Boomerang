#include"PlayerManeger.h"

PlayerManager::PlayerManager()
{
	_model = nullptr;
	//start_position, control_position1, control_position2, end_position
}

PlayerManager::~PlayerManager()
{
}

bool PlayerManager::Initialize()
{
	_model = GraphicsDevice.CreateAnimationModelFromFile(_T("MODEL/Player/player_animetion.X"));

	_model->SetScale(1.0f, 1.0f, 1.0f);
	_model->SetPosition(0, 0, 0);
	_model->SetRotation(0, 0, 0);

	if (_model == nullptr)
		return false;

    SimpleShape shape;
	shape.Type = Shape_Box;
	shape.Width  = 1;
	shape.Height = 1;
	shape.Depth  = 1;

	Material mat;
	mat.Diffuse = Color(1, 1, 1);
	mat.Ambient = Color(1, 1, 1);
	mat.Specular = Color(1, 1, 1);
	mat.Power = 10.0f;

	_collision = GraphicsDevice.CreateModelFromSimpleShape(shape);
	_collision->SetMaterial(mat);
	_collision->SetScale(1.0f, 2.0f, 1.0f);

	start_position    = Vector3_Zero;
	end_position      = Vector3_Zero;
	control_position1 = Vector3_Zero;
	control_position2 = Vector3_Zero;

	_callcount = 0;
	_invincibletime = 0;
	_invincibleflag = false;

	for (int i = 0; i < AnimationState::ALLTYPE; i++)
	{
		_model->SetTrackPosition(i, 0);
		_model->SetTrackEnable(i, FALSE);
	}

	_timelagstate = false;

	return true;
}

int PlayerManager::Update()
{
	KeyboardState key = Keyboard->GetState();
	KeyboardBuffer key_buffer = Keyboard->GetBuffer();

	start_position = _model->GetPosition() + _model->GetFrontVector();
	end_position = _model->GetPosition();

	Move(key);
	if (key.IsKeyDown(Keys_Space) && _animstate != AnimationState::SHOOT) {
		_power += 0.01;

		if (_power >= 2.0f) {
			_power = 2.0f;
		}
	}

	if (key_buffer.IsReleased(Keys_Space) && _animstate != AnimationState::SHOOT) {
		_animstate = AnimationState::SHOOT;
	}

	if (_shootstate) {
		if (_boomerang.Update(end_position) == 1)
		{
			_power = 0;
 			_shootstate = false;
		}
	}

	if (_animstate == AnimationState::DAMAGE) {
		_invincibletime += 1;

		if (_invincibletime <= 180) {
			_invincibleflag = true;
		}
		else {
			_invincibleflag = false;
			_animstate = AnimationState::WAIT;
		}
	}
	else {
		_invincibletime = 0;
	}

	_collision->SetPosition(_model->GetPosition() + Vector3(0.0f, 0.0f, 0.0f));
	return 0;
}

void PlayerManager::Draw()
{
	ChangeAnimation();
	_model->Draw();

#ifdef DEBUG
	GraphicsDevice.BeginAlphaBlend();
	if (_animstate == AnimationState::DAMAGE)
	{
	}
	else
		_collision->DrawAlpha(0.5f);
#endif
	GraphicsDevice.EndAlphaBlend();

	if (_shootstate) {
		_boomerang.Draw();
	}
}

void PlayerManager::Move(KeyboardState key)
{
	auto old_pos = _model->GetPosition();
	if (key.IsKeyDown(Keys_W)) {
		_model->Move(0.0f, 0.0f, 0.05f);
	}

	if (key.IsKeyDown(Keys_A)) {
		_model->Move(-0.05f, 0.0f, 0.0f);
	}

	if (key.IsKeyDown(Keys_S)) {
		_model->Move(0.0f, 0.0f, -0.05f);
	}

	if (key.IsKeyDown(Keys_D)) {
		_model->Move(0.05f, 0.0f, 0.0f);
	}

	if (key.IsKeyDown(Keys_Right)) {
		_model->Rotation(0.0f, 1.0f, 0.0f);
		_collision->Rotation(0.0f, 1.0f, 0.0f);
	}

	if (key.IsKeyDown(Keys_Left)) {
		_model->Rotation(0.0f, -1.0f, 0.0f);
		_collision->Rotation(0.0f, -1.0f, 0.0f);
	}

	if (_animstate == AnimationState::SHOOT)
	{
		return;
	}
	else if (_model->GetPosition() != old_pos)
	{
		_animstate = AnimationState::RUN;
	}
	else
	{
		_animstate = AnimationState::WAIT;
	}
}

//! @fn プレイヤーモデルのアニメーション切り替え
void PlayerManager::ChangeAnimation()
{
	auto index = _oldanimstate;

	_animation_count += GameTimer.GetElapsedSecond() * 2;

	//! 全てのアニメーショントラックを停止
	for (int i = 0; i < AnimationState::ALLTYPE; ++i)
	{
		_model->SetTrackEnable(i, FALSE);
	}

	//! アニメーショントラックと状態が違う場合アニメーショントラックを更新
	if (_animstate != index)
	{
		_oldanimstate = _animstate;
		_animation_count = 0;
	}

	if (_animstate == AnimationState::SHOOT && _animation_count > 2)
	{
		Shoot();
	}

	//! アニメーショントラックのアニメーションを指定した位置から再生
	_model->SetTrackEnable(_animstate, TRUE);

	_model->SetTrackPosition(_animstate, _animation_count);
}

void PlayerManager::Shoot()
{
	control_position1 = _model->GetPosition() + _model->GetFrontVector() * 6 + _model->GetRightVector() * 6;
	control_position2 = _model->GetPosition() + _model->GetFrontVector() * 6 + (-_model->GetRightVector()) * 6;
	_boomerang.Initialize(start_position, control_position1, control_position2, _power);

	_animstate = AnimationState::WAIT;
	_shootstate = true;
}

void PlayerManager::OnCollisionEnter()
{
	Damage();
	_animstate = AnimationState::DAMAGE;
	_callcount += 1;
}

int PlayerManager::CallOnCollisionEnter()
{
	return _callcount;
}

void  PlayerManager::Damage()
{
	if(!_invincibleflag)
		_hp -= 1;
}


Vector3 PlayerManager::Angle()
{
	return _model->GetRotation();
}

Vector3 PlayerManager::Position()
{
	return _model->GetPosition();
}

Vector3 PlayerManager::GetFrontVector()
{
	return _model->GetFrontVector();
}

Vector3 PlayerManager::GetUpVector()
{
	return _model->GetUpVector();
}

float PlayerManager::Power()
{
	return _power;
}