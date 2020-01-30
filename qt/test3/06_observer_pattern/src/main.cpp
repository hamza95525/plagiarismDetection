#include <iostream>
#include "Dummy.h"
int main() {
    Dummy dummy{};
    std::cout << "Result: " << dummy.integrate(0, 20) << std::endl;
    return 0;
}
