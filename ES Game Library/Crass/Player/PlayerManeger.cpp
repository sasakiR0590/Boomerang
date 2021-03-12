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

	return 0;
}

void PlayerManeger::Draw()
{
	_model->Draw();
}
