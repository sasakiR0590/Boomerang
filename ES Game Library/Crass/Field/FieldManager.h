#pragma once

#include"../../ESGLib.h"

class FieldManeger {
public:
    FieldManeger::FieldManeger();
    FieldManeger::~FieldManeger();

    bool    Initialize();
    void    Draw();
    Vector3 Position();

private:
    MODEL  _model;
};