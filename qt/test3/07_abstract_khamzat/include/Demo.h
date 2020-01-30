//
// Created by student on 25.11.2019.
//
#pragma once
#include "WidgetFactory.h"
class Demo{
private:
    std::shared_ptr<WidgetFactory> factory;
public:
    Demo(std::shared_ptr<WidgetFactory> factory);
    void run(std::string type);
};
