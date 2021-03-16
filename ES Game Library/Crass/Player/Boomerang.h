#pragma once

#include"../../ESGLib.h"

class Boomerang {
public:
    Boomerang::Boomerang(Vector3 start, Vector3 control1, Vector3 control2, Vector3 end);
    Boomerang::~Boomerang();
    bool    Initialize();
    int     Update();
    void    Draw();
    Vector3 Move();
    Vector3 ComeBack();
    MODEL GetCollision() { return _collision; }
private:

    Vector3 _position;
    Vector3 _angle;
    MODEL   _collision;
    MODEL   _model;

    float   _speed;
    float   _rotatespeed;

    Vector3 _point[4];
    bool    _gobackstate;
};