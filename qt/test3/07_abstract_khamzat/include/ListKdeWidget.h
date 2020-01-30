//
// Created by student on 25.11.2019.
//
#pragma once
#include "Widget.h"
class ListKdeWidget : public Widget{
private:
    int kdeVersion;
public:
    ListKdeWidget(int kdeVersion);
    void draw() override;
};
