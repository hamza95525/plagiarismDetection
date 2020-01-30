//
// Created by student on 25.11.2019.
//
#include "ListKdeWidget.h"
#include <iostream>
ListKdeWidget::ListKdeWidget(int kdeVersion) {
    this->kdeVersion = kdeVersion;
}
void ListKdeWidget::draw() {
    std::cout<< "ListKdeWidget" << "( " << this->kdeVersion << " )" << std::endl;
}
