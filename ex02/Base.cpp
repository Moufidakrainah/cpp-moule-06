#include "Base.hpp"

// Destructeur virtuel
Base::~Base() {}

// Génère un objet aléatoire de type A, B ou C
Base* generate(void) {
    std::srand(std::time(NULL));
    int r = std::rand() % 3;

    switch (r) {
        case 0:
            std::cout << "Generated: A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated: B" << std::endl;
            return new B();
        default:
            std::cout << "Generated: C" << std::endl;
            return new C();
    }
}

// Identification par pointeur
void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "Type via pointer: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type via pointer: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type via pointer: C" << std::endl;
    else
        std::cout << "Type via pointer: Unknown" << std::endl;
}

// Identification par référence
void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "Identified by reference: A" << std::endl;
        return;
    }
    catch (...) {} // attrape toute exception

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "Identified by reference: B" << std::endl;
        return;
    }
    catch (...) {}

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "Identified by reference: C" << std::endl;
        return;
    }
    catch (...) {}

    std::cout << "Type via reference: Unknown" << std::endl;
}
