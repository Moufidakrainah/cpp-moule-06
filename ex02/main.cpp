#include "Base.hpp"

int main() {
    Base* obj = generate();

    identify(obj);   // identification via pointeur
    identify(*obj);  // identification via référence

    delete obj;
    return 0;
}
