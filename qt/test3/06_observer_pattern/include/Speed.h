//
// Created by student on 18.11.2019.
//
#pragma once
#include "Observer.h"
class Speed : public Observer{
private:
    bool hasFirstValue;
    bool hasSecondValue;
    float firstValue;
    float secondValue;
public:
    float get();
    void notify(float d) override;
};
