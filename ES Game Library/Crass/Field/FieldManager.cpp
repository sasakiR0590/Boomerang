#include"FieldManager.h"

FieldManeger::FieldManeger()
{

}

FieldManeger::~FieldManeger()
{

}

bool FieldManeger::Initialize()
{
	_model = GraphicsDevice.CreateModelFromFile(_T("MODEL/Floor/floor_tst_02.X"));

	_model->SetScale(1.0f, 1.0f, 1.0f);
	_model->SetPosition(0, 0, 0);
	_model->SetRotation(0, 0, 0);

	if (_model == nullptr)
		return false;
}

void FieldManeger::Draw()
{
	_model->Draw();
}