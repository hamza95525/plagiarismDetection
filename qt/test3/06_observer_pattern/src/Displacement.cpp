//
// Created by student on 18.11.2019.
//
#include "Displacement.h"
void Displacement::set(float value) {
    this->value = value;
    notifyObservers(this->value);
}
