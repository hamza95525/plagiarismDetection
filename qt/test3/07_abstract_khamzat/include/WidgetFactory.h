//
// Created by student on 25.11.2019.
//
#pragma once
#include <memory>
#include <Widget.h>
class WidgetFactory{
public:
    virtual std::shared_ptr<Widget> create(std::string type) = 0;
};
