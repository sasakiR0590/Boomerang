#include"PlayerManeger.h"
#include <fstream>
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
	_model = GraphicsDevice.CreateAnimationModelFromFile(_T("MODEL/Player/hero_animetion_02.X"));

	_model->SetScale(1.0f);
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
	mat.Diffuse = Color(1.0f, 1.0f, 1.0f);
	mat.Ambient = Color(1.0f, 1.0f, 1.0f);
	mat.Specular = Color(1.0f, 1.0f, 1.0f);
	mat.Power = 1.0f;

	_collision = GraphicsDevice.CreateModelFromSimpleShape(shape);
	_collision->SetMaterial(mat);
	_collision->SetScale(1.0f, 2.0f, 1.0f);

	_invincibletime = 0;
	_invincibleflag = false;

	for (int i = 0; i < AnimationState::ALLTYPE; i++)
	{
		_model->SetTrackPosition(i, 0);
		_model->SetTrackEnable(i, FALSE);
	}

	_playermove = 0.0f;
	_max_invincibletime = 0;
	_frontdistance = 0.0f;
	_sidedistance = 0.0f;

	_rotate_direction = 0.0f;
	_frontvector      = Vector3_Zero;
	_rotation         = 0.0f;
	_atan2_change     = 0.0f;

	//!テスト用
	_test_rotation_now = 0.0f;
	_test_rotation_90  = 0.0f;

	InputDevice.CreateGamePad(1);

	LoadCSV::Instance().LoadStatus("csvFile/Player/PlayerStatus.csv");
	_playermove = LoadCSV::Instance()._status.at("#動く速度");
	_max_invincibletime = LoadCSV::Instance()._status.at("#無敵時間");
	_frontdistance = LoadCSV::Instance()._status.at("#ブーメランを飛ばす距離(前)");
	_sidedistance = LoadCSV::Instance()._status.at("#ブーメランを飛ばす距離(横)");

	return true;
}

int PlayerManager::Update()
{
	KeyboardState key = Keyboard->GetState();
	KeyboardBuffer key_buffer = Keyboard->GetBuffer();

	GamePadState pad = GamePad(0)->GetState();
	GamePadBuffer pad_buffer = GamePad(0)->GetBuffer();

	KeyboardMove(key);
	PadMove(pad);

	if ((key.IsKeyDown(Keys_Space) || pad.Buttons[3]) && _animstate != AnimationState::SHOOT) {
		_power += 0.01;
		if (_power >= 2.0f) {
			_power = 2.0f;
		}
	}

	if ((key_buffer.IsReleased(Keys_Space) || pad_buffer.IsReleased(GamePad_Button4)) && !_shootstate) {
		_animstate = AnimationState::SHOOT;
	}

	if (_shootstate) {
		if (_boomerang.Update(_model->GetPosition()) == 1)
		{
			_power = 0;
 			_shootstate = false;
		}
	}

	if (_animstate == AnimationState::DAMAGE) {
		_invincibletime += 1;

		if (_invincibletime <= _max_invincibletime) {
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
		//_collision->DrawAlpha(0.5f);

	GraphicsDevice.EndAlphaBlend();
#endif

	if (_shootstate) {
		_boomerang.Draw();
	}
}

void PlayerManager::KeyboardMove(KeyboardState key)
{
	auto old_pos = _model->GetPosition();
	if (key.IsKeyDown(Keys_W)) {
		_model->Move(0.0f, 0.0f, _playermove);
	}

	if (key.IsKeyDown(Keys_A)) {
		_model->Move(-_playermove, 0.0f, 0.0f);
	}

	if (key.IsKeyDown(Keys_S)) {
		_model->Move(0.0f, 0.0f, -_playermove);
	}

	if (key.IsKeyDown(Keys_D)) {
		_model->Move(_playermove, 0.0f, 0.0f);
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

void PlayerManager::PadMove(GamePadState pad)
{
	auto old_pos = _model->GetPosition();

	if (pad.X != 0.0f || pad.Y != 0.0f) {
#ifdef _DEBUG
		_test_rotation_now = MathHelper_Atan2(pad.Y, pad.X);
		_test_rotation_90  = MathHelper_Atan2(pad.Y, pad.X) + 90.0f;
#endif

		_rotate_direction = MathHelper_Atan2(pad.Y, pad.X) + 90.0f;

		if (_rotation >= 0 && _rotate_direction >= -90.0f && _rotate_direction < 0.0f)
			_rotate_direction += 360.0f;

		_rotation = MathHelper_Lerp(_rotation, _rotate_direction, GameTimer.GetElapsedSecond() * 10);

		_model->SetRotation(0.0f, _rotation, 0.0f);
		_model->Move(0.0f, 0.0f, _playermove);
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

	if (_animstate == AnimationState::SHOOT && _animation_count >= 1)
	{
		Shoot();
	}

	//! アニメーショントラックのアニメーションを指定した位置から再生
	_model->SetTrackEnable(_animstate, TRUE);

	_model->SetTrackPosition(_animstate, _animation_count);
}

void PlayerManager::Shoot()
{
	Vector3 start_position = _model->GetPosition() + _model->GetFrontVector();
	Vector3 control_position1 = _model->GetPosition() + _model->GetFrontVector() * _frontdistance + _model->GetRightVector() * _sidedistance;
	Vector3 control_position2 = _model->GetPosition() + _model->GetFrontVector() * _frontdistance + (-_model->GetRightVector()) * _sidedistance;
	_boomerang.Initialize(start_position, control_position1, control_position2, _power);

	_animstate = AnimationState::WAIT;
	_shootstate = true;
}

void PlayerManager::OnCollisionEnter()
{
	Damage();
	_animstate = AnimationState::DAMAGE;
}

void  PlayerManager::Damage()
{
	if(!_invincibleflag)
		_hp -= 1;
}

Vector3 PlayerManager::GetPosition()
{
	return _model->GetPosition();
}


float PlayerManager::TestRotationNow()
{
	return _rotation;
}

float PlayerManager::TestRotation90()
{
	return _test_rotation_90;
}
