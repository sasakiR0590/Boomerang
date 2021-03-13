#pragma once

#include"..//..//ESGLib.h"

class Boomerang {
public:
    Boomerang::Boomerang(Vector3 start, Vector3 control1, Vector3 control2, Vector3 end);
    Boomerang::~Boomerang();
    bool    Initialize();
    int     Update();
    void    Draw();
    Vector3 Move();
private:

    Vector3 _position;
    Vector3 _angle;
    MODEL   _colisition;
    MODEL   _model;

    float   _speed;

    Vector3 _point[4];
};