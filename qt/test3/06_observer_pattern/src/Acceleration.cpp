//
// Created by student on 18.11.2019.
//
#include "Acceleration.h"
float Acceleration::get() {
    if(hasFirstValue == 1 && hasSecondValue == 1 && hasThirdValue == 1)
        return (thirdValue-secondValue) - (secondValue-firstValue);
    else if (hasFirstValue == 1 && hasSecondValue == 1 && hasThirdValue == 0)
        return hasSecondValue-hasFirstValue;
     else if (hasFirstValue == 1 && hasSecondValue == 0 && hasThirdValue == 0)
        return 0;
}
void Acceleration::notify(float d) {
    if(hasFirstValue == 0) {
        firstValue = d;
        hasFirstValue = true;
    }
    else if(hasFirstValue == 1 && hasSecondValue == 0) {
        secondValue = firstValue;
        firstValue = d;
        hasSecondValue = true;
    }
    else if(hasFirstValue == 1 && hasSecondValue == 1 && hasThirdValue == 0){
        thirdValue = secondValue;
        secondValue = firstValue;
        firstValue = d;
        hasThirdValue = true;
    }
}
