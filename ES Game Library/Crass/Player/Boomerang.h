#pragma once

#include"../../ESGLib.h"

class Boomerang {
public:
    Boomerang::Boomerang();
    Boomerang::~Boomerang();
    bool    Initialize(Vector3 start, Vector3 control1, Vector3 control2);
    int     Update(Vector3 _playerposition);
    void    Draw();
    Vector3 Move();
    Vector3 ComeBack();
    MODEL GetCollision() { return _collision; }
    void AddScale();
    void AddScaleReset();
private:

    Vector3 _position;
    Vector3 _angle;
    MODEL   _collision;
    MODEL   _model;

    float   _speed;
    float   _rotatespeed;

    Vector3 _point[4];
    bool    _gobackstate;
    Vector3 _endposition;

    float _addscale = 1.0f;
};