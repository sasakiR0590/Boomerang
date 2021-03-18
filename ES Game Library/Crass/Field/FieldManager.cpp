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
	_model->SetPosition(0.0f, 0.0f, 0.0f);
	_model->SetRotation(0.0f, 0.0f, 0.0f);

	if (_model == nullptr)
		return false;

	Material material;
	material.Diffuse = Color(0.0f, 0.0f, 1.0f);
	material.Ambient = Color(0.5f, 0.5f, 0.5f);
	material.Specular = Color(1.0f, 1.0f, 1.0f);
	material.Power = 10.0f;
	_model->SetMaterial(material);
}

void FieldManeger::Draw()
{
	_model->Draw();
}