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
	//_boomerang->Initialize();

	//_model = GraphicsDevice.CreateAnimationModelFromFile(_T("MODEL/Player/hero.X"));
	_model = GraphicsDevice.CreateAnimationModelFromFile(_T("MODEL/Player/walk_animetion_0323.X"));


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

	start_position = Vector3_Zero;
	end_position   = Vector3_Zero;

	_callcount = 0;
	_invincibletime = 0;
	_invincibleflag = false;

	return true;
}

int PlayerManager::Update()
{
	KeyboardState key = Keyboard->GetState();
	KeyboardBuffer key_buffer = Keyboard->GetBuffer();

	//_model->SetTrackEnable(0, TRUE);
	
	start_position = _model->GetPosition() + _model->GetFrontVector();
	end_position = _model->GetPosition();

	Move(key);
	if (key.IsKeyDown(Keys_Space) && _animstate != AnimationState::SHOOT) {
		_power += 0.01;
	}

	if (key_buffer.IsReleased(Keys_Space) && _animstate != AnimationState::SHOOT) {
		Shoot();
		_power = 0;
	}

	if (_animstate == AnimationState::SHOOT) {
		if (_boomerang.Update(end_position) == 1)
		{
			_animstate   = AnimationState::WAIT;
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
	_model->Draw();
	_model->SetTrackEnable(0, TRUE);

#ifdef DEBUG
	GraphicsDevice.BeginAlphaBlend();
	if (_animstate == AnimationState::DAMAGE)
	{
	}
	else
		_collision->DrawAlpha(0.5f);
#endif
	GraphicsDevice.EndAlphaBlend();

	if (_animstate == AnimationState::SHOOT) {
		_boomerang.Draw();
	}
}

void PlayerManager::Move(KeyboardState key)
{
	_animstate = AnimationState::RUN;

	if (key.IsKeyDown(Keys_W)) {
		_model->Move(0.0f, 0.0f, 0.1f);
		_model->SetTrackEnable(0, TRUE);
	}

	if (key.IsKeyDown(Keys_A)) {
		_model->Move(-0.1f, 0.0f, 0.0f);
		_model->SetTrackEnable(0, TRUE);
	}

	if (key.IsKeyDown(Keys_S)) {
		_model->Move(0.0f, 0.0f, -0.1f);
		_model->SetTrackEnable(0, TRUE);
	}

	if (key.IsKeyDown(Keys_D)) {
		_model->Move(0.1f, 0.0f, 0.0f);
		_model->SetTrackEnable(0, TRUE);
	}

	if (key.IsKeyDown(Keys_Right)) {
		_model->Rotation(0.0f, 1.0f, 0.0f);
	}

	if (key.IsKeyDown(Keys_Left)) {
		_model->Rotation(0.0f, -1.0f, 0.0f);
	}
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

void PlayerManager::Shoot()
{
	_animstate = AnimationState::SHOOT;

	Vector3 control_position1 = _model->GetPosition() + _model->GetFrontVector() * 6 + _model->GetRightVector() * 6;
	Vector3 control_position2 = _model->GetPosition() + _model->GetFrontVector() * 6 + (-_model->GetRightVector()) * 6;

	_boomerang.Initialize(start_position, control_position1, control_position2,_power);
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