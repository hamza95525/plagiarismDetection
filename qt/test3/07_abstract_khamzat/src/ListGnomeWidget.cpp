//
// Created by student on 25.11.2019.
//
#include "ListGnomeWidget.h"
#include <iostream>
ListGnomeWidget::ListGnomeWidget(int gnomeVersion) {
    this->gnomeVersion = gnomeVersion;
}
void ListGnomeWidget::draw() {
    std::cout<< "ListGnomeWidget" << "( " << this->gnomeVersion << " )" << std::endl;
}
