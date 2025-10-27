#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

class Identify {
public:
    // Forme canonique
    Identify();
    Identify(const Identify& other);
    Identify& operator=(const Identify& other);
    ~Identify();

    // Méthodes demandées par l'exercice
    Base* generate();
    void identify(Base* p);
    void identify(Base& p);
};

#endif

