//
// Created by student on 25.11.2019.
//
#pragma once
#include "Widget.h"
class ListGnomeWidget : public Widget{
private:
    int gnomeVersion;
public:
    ListGnomeWidget(int gnomeVersion);
    void draw() override;
};
