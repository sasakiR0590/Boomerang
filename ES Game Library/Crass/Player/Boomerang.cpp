#include"Boomerang.h"

Boomerang::Boomerang(Vector3 start, Vector3 control1, Vector3 control2, Vector3 end)
{
	_point[0] = start;
	_point[1] = control1;
	_point[2] = control2;
	_point[3] = end;

}

Boomerang::~Boomerang()
{

}

bool Boomerang::Initialize()
{
	_model = GraphicsDevice.CreateModelFromFile(_T("MODEL/Boomerang/ono_boomerang.X"));
	_model->SetScale(3.0f, 3.0f, 3.0f);
	_model->SetPosition(0, 0, 0);
	_model->SetRotation(0, 0, 0);

	if (_model == nullptr)
		return false;

	_speed = 1.0f;
	return true;
}

int Boomerang::Update()
{
	_model->SetPosition(Move());
	return 0;
}

void Boomerang::Draw()
{
	_model->Draw();
}

Vector3 Boomerang::Move()
{
	_speed += 0.1f;
	Vector3 _bezier = Vector3_Bezier(_point[0], _point[1], _point[2], _point[3], _speed);

	return _bezier;
}
