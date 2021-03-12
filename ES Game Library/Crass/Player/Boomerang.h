#pragma once

#include"..//..//ESGLib.h"

class Boomerang {
public:
    Boomerang::Boomerang();
    Boomerang::~Boomerang();
    bool    Initialize();
    int     Update();
    void    Draw();
private:
    Vector3 Move();

    Vector3 _position;
    Vector3 _angle;
    MODEL   _colisition;
    MODEL   _model;
};