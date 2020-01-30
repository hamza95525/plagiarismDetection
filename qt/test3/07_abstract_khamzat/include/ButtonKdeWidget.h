//
// Created by student on 25.11.2019.
//
#pragma once
#include "Widget.h"
class ButtonKdeWidget : public Widget{
private:
    int kdeVersion;
public:
    ButtonKdeWidget(int kdeVersion);
    void draw() override;
};
