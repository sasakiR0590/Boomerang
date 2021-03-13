#include"Boomerang.h"

Boomerang::Boomerang()
{

}

Boomerang::~Boomerang()
{

}

bool Boomerang::Initialize()
{
	_model = GraphicsDevice.CreateModelFromFile(_T("MODEL/Boomerang/ono_boomerang.X"));
	_model->SetScale(1.0f, 1.0f, 1.0f);
	_model->SetPosition(0, 0, 0);
	_model->SetRotation(0, 0, 0);

	if (_model == nullptr)
		return false;

	return true;
}

int Boomerang::Update()
{

	return 0;
}

void Boomerang::Draw()
{
	_model->Draw();

}