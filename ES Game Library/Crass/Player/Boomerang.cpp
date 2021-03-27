#include"Boomerang.h"

Boomerang::Boomerang()
{

}

Boomerang::~Boomerang()
{

}

bool Boomerang::Initialize(Vector3 start, Vector3 control1, Vector3 control2, float power)
{
	_model = GraphicsDevice.CreateModelFromFile(_T("MODEL/Boomerang/ono_boomerang.X"));
	_model->SetScale(1.0f + power);
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
	_collision->SetScale(0.1f + power);
	_collision->SetMaterial(mat);
	_speed = 0.0f;
	_rotatespeed = 0.0f;
	_gobackstate = false;

	_point[0] = start;
	_point[1] = control1;
	_point[2] = control2;

	_angle = Vector3_Zero;

	return true;
}

int Boomerang::Update(Vector3 playerposition)
{

	if (_speed >= 0.5 && Vector3_Distance(_model->GetPosition(), playerposition) <= 1)
	{
		return 1;
	}

	_collision->SetPosition(_model->GetPosition() + Vector3(0.0f, 0.0f, 0.0f));
	_model->SetPosition(Move(playerposition));

	return 0;
}

void Boomerang::Draw()
{
	_model->Draw();
#ifdef DEBUG
	GraphicsDevice.BeginAlphaBlend();
	_collision->DrawAlpha(0.5f);
#endif
}

Vector3 Boomerang::Move(Vector3 endpos)
{
	_speed += 0.01f;
	_rotatespeed += 10.0f;
	_model->SetRotation(0.0f, _rotatespeed, 0.0f);
	_collision->SetRotation(0.0f, _rotatespeed, 0.0f);
	Vector3 _bezier = Vector3_Bezier(_point[0], _point[1], _point[2], endpos, _speed);

	return _bezier;
}