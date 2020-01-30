#include "Dummy.h"
int Dummy::integrate(int start, int stop) const {
    int integral = 0;
    for (int i = start; i <= stop; i++) {
        integral += i;
    }
    return integral;
}
