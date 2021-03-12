#include"PlayerManeger.h"

PlayerManeger::PlayerManeger()
{
	_model = nullptr;
}

PlayerManeger::~PlayerManeger()
{

}

bool PlayerManeger::Initialize()
{

	_model = GraphicsDevice.CreateModelFromFile(_T("MODEL/Player/kariMan_1.X"));

	_model->SetScale(1.0f, 1.0f, 1.0f);
	_model->SetPosition(0, 0, 0);
	_model->SetRotation(0, 0, 0);

	if (_model == nullptr)
		return false;

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
	return 0;
}

void PlayerManeger::Draw()
{
	_model->Draw();
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