//
// Created by student on 25.11.2019.
//
#include "CheckBoxKdeWidget.h"
#include <iostream>
CheckBoxKdeWidget::CheckBoxKdeWidget(int kdeVersion) {
    this->kdeVersion = kdeVersion;
}
void CheckBoxKdeWidget::draw() {
    std::cout<< "CheckBoxKdeWidget" << "( " << this->kdeVersion << " )" << std::endl;
}
