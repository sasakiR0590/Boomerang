#pragma once

#include"../../ESGLib.h"

class Boomerang {
public:
    Boomerang::Boomerang();
    Boomerang::~Boomerang();

    bool    Initialize(Vector3 start, Vector3 control1, Vector3 control2, float power);
    int     Update(Vector3 playerposition);
    void    Draw();

    MODEL GetCollision() { return _collision; }
private:
    Vector3 Move(Vector3 endpos);

    Vector3 _position;
    Vector3 _angle;

    //! ベジエ用ポイント
    Vector3 _point[4];

    MODEL   _collision;
    MODEL   _model;

    //!スピード
    float   _speed;
    float   _rotatespeed;

    //!戻ってくるステート切り替え
    bool    _gobackstate;
};