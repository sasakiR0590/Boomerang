#include"FieldManager.h"

FieldManeger::FieldManeger()
{
	_model = nullptr;
}

FieldManeger::~FieldManeger()
{

}

bool FieldManeger::Initialize()
{
	_model = GraphicsDevice.CreateModelFromFile(_T("MODEL/Floor/floor_tst_02.X"));

	_model->SetScale(1.25);
	_model->SetPosition(0.0f, 0.0f, 0.0f);
	_model->SetRotation(0.0f, 0.0f, 0.0f);

	if (_model == nullptr)
		return false;

	Material material;
	material.Diffuse = Color(1.0f, 1.0f, 1.0f);
	material.Ambient = Color(1.0f, 1.0f, 1.0f);
	material.Specular = Color(1.0f, 1.0f, 1.0f);
	material.Power = 1.0f;
	_model->SetMaterial(material);

	return true;
}

void FieldManeger::Draw()
{
	_model->Draw();
}

Vector3 FieldManeger::Position()
{
	return _model->GetPosition();
}