#pragma once

#include"../../ESGLib.h"

class FieldManeger {
public:
    FieldManeger::FieldManeger();
    FieldManeger::~FieldManeger();

    bool    Initialize();
    void    Draw();

private:
    MODEL _model;
};