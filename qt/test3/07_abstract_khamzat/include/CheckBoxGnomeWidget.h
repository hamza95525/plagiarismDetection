//
// Created by student on 25.11.2019.
//
#pragma once
#include "Widget.h"
class CheckBoxGnomeWidget : public Widget{
private:
    int gnomeVersion;
public:
    CheckBoxGnomeWidget(int gnomeVersion);
    void draw() override;
};
