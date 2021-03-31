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

	_getline_count = 0;

	//InputDevice.CreateGamePad(1);

	LoadCSV::Instance().LoadStatus("csvFile/Player/PlayerStatus.csv");
	_playermove = LoadCSV::Instance()._filedata[0];
	_max_invincibletime = LoadCSV::Instance()._filedata[1];
	_frontdistance = LoadCSV::Instance()._filedata[2];
	_sidedistance = LoadCSV::Instance()._filedata[3];

	return true;
}

int PlayerManager::Update()
{
	KeyboardState key = Keyboard->GetState();
	KeyboardBuffer key_buffer = Keyboard->GetBuffer();

	//GamePadState pad = GamePad(0)->GetState();
	//GamePadBuffer pad_buffer = GamePad(0)->GetBuffer();

	KeyboardMove(key);
	//PadMove(pad);

	if (key.IsKeyDown(Keys_Space) && _animstate != AnimationState::SHOOT) {
		_power += 0.01;

		if (_power >= 2.0f) {
			_power = 2.0f;
		}
	}

	if (key_buffer.IsReleased(Keys_Space) && !_shootstate) {
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

//void PlayerManager::PadMove(GamePadState pad)
//{
//	auto old_pos = _model->GetPosition();
//
//	Vector3 vector(pad.X, 0.0f, -pad.Y);
//	vector = Vector3_Normalize(vector);
//	_model->Move(vector * _playermove);
//
//	if (_animstate == AnimationState::SHOOT)
//	{
//		return;
//	}
//	else if (_model->GetPosition() != old_pos)
//	{
//		_animstate = AnimationState::RUN;
//	}
//	else
//	{
//		_animstate = AnimationState::WAIT;
//	}
//}

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

//void PlayerManager::LoadCSV()
//{
//	std::ifstream infile("csvFile/Player/PlayerStatus.csv");
//	std::string filename;
//	TCHAR t_filename[256];
//
//	std::string dummy_line;
//
//	while (true)
//	{
//		_getline_count++;
//
//		getline(infile, dummy_line);
//
//		if (infile.eof())
//			break;
//
//		if(_getline_count == 2)
//			infile >> _playermove;
//        
//		if(_getline_count == 4)
//			infile >> _max_invincibletime;
//
//		if (_getline_count == 6)
//			infile >> _frontdistance;
//
//		if(_getline_count == 8)
//			infile >> _sidedistance;
//	}
//
//}