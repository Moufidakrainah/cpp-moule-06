#include "Identify.hpp"
#include <iostream>

int main() {
    Base* obj = generate();

    std::cout << "Identification via pointeur : ";
    identify(obj);

    std::cout << "Identification via référence : ";
    identify(*obj);

    delete obj;
    return 0;
}
