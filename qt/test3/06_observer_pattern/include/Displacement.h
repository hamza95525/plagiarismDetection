//
// Created by student on 18.11.2019.
//
#pragma once
#include "Obsevable.h"
class Displacement : public Observable{
private:
    float value;
public:
    void set(float);
};
