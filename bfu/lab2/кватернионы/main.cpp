#include <iostream>
#include "gcomplex.h"
#include "vector3.h"

int main() {
    gcomplex a, b;
    std::cin >> a >> b;
    std::cout << "a: " << a << "\nb: " << b << "\na + b: " << a + b << "\na * b: ";
    std::cout << a * b << "\na * b^-1: " << a * invert(b);
    return 0;
}
