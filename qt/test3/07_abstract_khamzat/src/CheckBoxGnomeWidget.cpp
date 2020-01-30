//
// Created by student on 25.11.2019.
//
#include "CheckBoxGnomeWidget.h"
#include <iostream>
CheckBoxGnomeWidget::CheckBoxGnomeWidget(int gnomeVersion) {
    this->gnomeVersion = gnomeVersion;
}
void CheckBoxGnomeWidget::draw() {
    std::cout<< "CheckBoxGnomeWidget" << "( " << this->gnomeVersion << " )" << std::endl;
}
