//
// Created by student on 25.11.2019.
//
#include "ButtonKdeWidget.h"
#include <iostream>
ButtonKdeWidget::ButtonKdeWidget(int kdeVersion) {
    this->kdeVersion = kdeVersion;
}
void ButtonKdeWidget::draw() {
    std::cout<< "ButtonKdeWidget" << "( " << this->kdeVersion << " )" << std::endl;
}
