#include"Boomerang.h"

Boomerang::Boomerang()
{

}

Boomerang::~Boomerang()
{

}

bool Boomerang::Initialize(Vector3 start, Vector3 control1, Vector3 control2, float power, float speed)
{
	_model = GraphicsDevice.CreateModelFromFile(_T("MODEL/Boomerang/boomerang_v2.X"));
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
	mat.Diffuse = Color(1.0f, 1.0f, 1.0f);
	mat.Ambient = Color(1.0f, 1.0f, 1.0f);
	mat.Specular = Color(1.0f, 1.0f, 1.0f);
	mat.Power = 1.0f;

	_collision = GraphicsDevice.CreateModelFromSimpleShape(shape);
	_collision->SetScale(0.1f + power);
	_collision->SetScale(_collision->GetScale() * 5);
	_collision->SetMaterial(mat);

	_addspeed    = speed;
	_speed       = 0.0f;
	_rotatespeed = 0.0f;

	_point[0] = start;
	_point[1] = control1;
	_point[2] = control2;

	_angle = Vector3_Zero;

	return true;
}

int Boomerang::Update(Vector3 playerposition, GamePadState pad)
{

	if (_speed >= 0.5f && Vector3_Distance(_model->GetPosition(), playerposition) <= 1)
	{
		_model->SetPosition(Vector3_Zero);
		return 1;
	}

	if (pad.Y2 != 0.0f || pad.X3 != 0.0f) {
		_point[1].x += pad.Y2 * 0.00001;
		_point[2].x += pad.Y2 * 0.00001;
		_point[1].z += pad.X3 * -0.00001;
		_point[2].z += pad.X3 * -0.00001;
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
	_speed += _addspeed;
	_rotatespeed += 50.0f;
	_model->SetRotation(0.0f, _rotatespeed, 0.0f);
	_collision->SetRotation(0.0f, _rotatespeed, 0.0f);
	Vector3 _bezier = Vector3_Bezier(_point[0], _point[1], _point[2], endpos, _speed);

	return _bezier;
}