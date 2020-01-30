//
// Created by student on 18.11.2019.
//
#include "Speed.h"
float Speed::get() {
   // if(hasFirstValue == 1 && hasSecondValue == 1)
        return secondValue - firstValue;
}
void Speed::notify(float d) {
    if(hasFirstValue == 0) {
        firstValue = d;
        hasFirstValue = true;
    }
    else if(hasSecondValue == 0) {
        secondValue = d;
        hasSecondValue = true;
    }
    else {
        firstValue = secondValue;
        secondValue = d;
    }
}
