#include"Boomerang.h"

Boomerang::Boomerang()
{

}

Boomerang::~Boomerang()
{

}

bool Boomerang::Initialize(Vector3 start, Vector3 control1, Vector3 control2)
{
	_model = GraphicsDevice.CreateModelFromFile(_T("MODEL/Boomerang/ono_boomerang.X"));
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
	_collision = GraphicsDevice.CreateModelFromSimpleShape(shape);
	_collision->SetMaterial(mat);
	_collision->SetScale(0.5);

	_speed = 0.0f;
	_rotatespeed = 0.0f;
	_gobackstate = false;

	_point[0] = start;
	_point[1] = control1;
	_point[2] = control2;
	_endposition = Vector3_Zero;

	return true;
}

int Boomerang::Update(Vector3 _playerposition)
{
	if (_speed >= 0.5 && Vector3_Distance(_model->GetPosition(), _endposition) <= 1)
	{
		return 1;
	}
	_endposition = _playerposition;
	_collision->SetRotation(_model->GetRotation());

	_model->SetPosition(Move());
	_collision->SetPosition(_model->GetPosition() + Vector3(0.0f, 0.0f, 0.0f));

	return 0;
}

void Boomerang::Draw()
{
	_model->Draw();
	_collision->Draw();
}

Vector3 Boomerang::Move()
{
	_speed += 0.01f;
	_rotatespeed += 10.0f;
	_model->SetRotation(0.0f, _rotatespeed, 0.0f);
	Vector3 _bezier = Vector3_Bezier(_point[0], _point[1], _point[2], _endposition, _speed);

	return _bezier;
}