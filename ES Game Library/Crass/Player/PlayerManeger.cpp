#include"PlayerManeger.h"

PlayerManeger::PlayerManeger()
{
	_model = nullptr;
	_boomerang = nullptr;
	//start_position, control_position1, control_position2, end_position
}

PlayerManeger::~PlayerManeger()
{

}

bool PlayerManeger::Initialize()
{
	//_boomerang->Initialize();

	_model = GraphicsDevice.CreateModelFromFile(_T("MODEL/Player/kariMan_1.X"));

	_model->SetScale(1.0f, 1.0f, 1.0f);
	_model->SetPosition(0, 0, 0);
	_model->SetRotation(0, 0, 0);

	if (_model == nullptr)
		return false;

    SimpleShape shape;
	shape.Type = Shape_Box;
	shape.Width = 10;
	shape.Height = 10;
	shape.Depth = 10;

	Material mat;
	mat.Diffuse = Color(1, 1, 1);
	mat.Ambient = Color(1, 1, 1);
	mat.Specular = Color(1, 1, 1);
	_collision = GraphicsDevice.CreateModelFromSimpleShape(shape);
	_collision->SetMaterial(mat);
	_collision->SetScale(3.0f, 6.0f, 3.0f);

	return true;
}

int PlayerManeger::Update()
{

	KeyboardState key = Keyboard->GetState();
	KeyboardBuffer key_buffer = Keyboard->GetBuffer();

	if (key.IsKeyDown(Keys_W)) {
		_model->Move(0.0f, 0.0f, 1.0f);

	}

	if (key.IsKeyDown(Keys_A)) {
		_model->Move(-1.0f, 0.0f, 0.0f);

	}

	if (key.IsKeyDown(Keys_S)) {
		_model->Move(0.0f, 0.0f, -1.0f);

	}

	if (key.IsKeyDown(Keys_D)) {
		_model->Move(1.0f, 0.0f, 0.0f);

	}

	if (key.IsKeyDown(Keys_Right)) {
		_model->Rotation(0.0f, 5.0f, 0.0f);

	}

	if (key.IsKeyDown(Keys_Left)) {
		_model->Rotation(0.0f, -5.0f, 0.0f);

	}

	if (key.IsKeyDown(Keys_Space)) {
		Shoot();

	}

	if (_animstate == AnimationState::SHOOT) {
		_boomerang->Update();
	}

	_collision->SetPosition(_model->GetPosition() + Vector3(0.0f, 20.0f, 0.0f));
	_collision->SetRotation(_model->GetRotation());
	return 0;
}

void PlayerManeger::Draw()
{
	_model->Draw();
	_collision->Draw();

	if (_animstate == AnimationState::SHOOT) {
		_boomerang->Draw();
	}
}

Vector3 PlayerManeger::Position()
{
	return _model->GetPosition();
}

Vector3 PlayerManeger::GetFrontVector()
{
	return _model->GetFrontVector();
}

Vector3 PlayerManeger::GetUpVector()
{
	return _model->GetUpVector();
}

void PlayerManeger::Shoot()
{
	_animstate = AnimationState::SHOOT;
	Vector3 start_position    = _model->GetPosition();
	Vector3 control_position1 = start_position + Vector3(600.0f,0.0f,600.0f);
	Vector3 control_position2 = start_position + Vector3(-600.0f,0.0f,600.0f);
	Vector3 end_position      = start_position;

	if(_boomerang == nullptr)
	_boomerang = new Boomerang(start_position, control_position1, control_position2, end_position);
	_boomerang->Initialize();
}

void PlayerManeger::OnCollisionEnter()
{
}
