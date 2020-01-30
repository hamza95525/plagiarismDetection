//
// Created by student on 18.11.2019.
//
#pragma once
#include "Observer.h"
class Acceleration : public Observer{
private:
    bool hasFirstValue;
    bool hasSecondValue;
    bool hasThirdValue;
    float firstValue;
    float secondValue;
    float thirdValue;
public:
    void notify(float d) override;
    float get();
};
