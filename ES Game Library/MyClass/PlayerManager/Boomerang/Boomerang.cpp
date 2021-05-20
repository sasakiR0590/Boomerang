#include"Boomerang.h"
#include"../../Data/MyAlgorithm.h"
Boomerang::Boomerang()
{

}

Boomerang::~Boomerang()
{

}

bool Boomerang::Initialize(Vector3 start, Vector3 control1, Vector3 control2, float power, float speed, std::vector<Vector3> stick)
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
	if (stick.size() != 0) {
		_point[1] = control1 + *(stick.rbegin() + 1);
		_point[2] = control2 + *stick.rbegin();
	}
	else {
		_point[1] = control1;
		_point[2] = control2;
	}
	_angle = Vector3_Zero;
	for (int i = 0; i < AFTERIMAGE; i++)
	{
		_oldpos[i] = Vector3_Zero;
	}
	_count = 0;
	return true;
}

int Boomerang::Update(Vector3 playerposition, GamePadState pad)
{
	_oldpos[_count] = _model->GetPosition();
	_count++;
	_count = IntWrap(_count, 0, AFTERIMAGE);
	if (_speed >= 0.5f && Vector3_Distance(_model->GetPosition(), playerposition) <= 1)
	{
		if (_oldpos[AFTERIMAGE - 1] == _model->GetPosition())
		{
			_model->SetPosition(Vector3_Zero);
			return 1;
		}
		return 0;
	}

	if (pad.Y2 != 0.0f || pad.X3 != 0.0f) {
		_point[1].x += pad.Y2 * 0.000005;
		_point[2].x += pad.Y2 * 0.000005;
		_point[1].z += pad.X3 * -0.000005;
		_point[2].z += pad.X3 * -0.000005;
	}
	_collision->SetPosition(_model->GetPosition() + Vector3(0.0f, 0.0f, 0.0f));
	_model->SetPosition(Move(playerposition));

	return 0;
}

void Boomerang::Draw()
{
	auto pos = _model->GetPosition();
	_model->Draw();
	for (int i = 0; i < AFTERIMAGE; i++)
	{
		if (_oldpos[i] != Vector3_Zero && i % 3 == 0)
		{
			_model->SetPosition(_oldpos[i]);
			_model->DrawAlpha(0.1 + i*0.04);
		}
	}
	_model->SetPosition(pos);
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