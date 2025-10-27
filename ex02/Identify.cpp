#include "Identify.hpp"
#include <cstdlib>   // rand, srand
#include <ctime>     // time
#include <iostream>  // cout, endl

Base* generate(void)
{
    std::srand(static_cast<unsigned int>(std::time(0))); // initialisation du générateur aléatoire
    int random = std::rand() % 3;

    if (random == 0)
    {
        std::cout << "Generated: A" << std::endl;
        return new A();
    }
    else if (random == 1)
    {
        std::cout << "Generated: B" << std::endl;
        return new B();
    }
    else
    {
        std::cout << "Generated: C" << std::endl;
        return new C();
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Identified by pointer: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Identified by pointer: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Identified by pointer: C" << std::endl;
    else
        std::cout << "Identified by pointer: Unknown type" << std::endl;
}

void identify(Base& p)
{
    // On tente les cast par référence, sans utiliser std::bad_cast
    // On utilise un bloc vide pour chaque essai de dynamic_cast

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

    std::cout << "Identified by reference: Unknown type" << std::endl;
}