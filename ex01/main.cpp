#include <iostream>
#include "Serializer.hpp"

int main() {
    Data d;
    d.value = 42;
    d.otherValue = 3.14;

    std::cout << "Adresse originale de d : " << &d << std::endl;

    /* Sérialisation */
    uintptr_t raw = Serializer::serialize(&d);
    std::cout << "Valeur sérialisée : " << raw << std::endl;

    /* Désérialisation */
    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Adresse après désérialisation : " << ptr << std::endl;

    /* Vérification */
    if (ptr == &d)
        std::cout << "Succès : les adresses correspondent !" << std::endl;
    else
        std::cout << "Erreur : les adresses ne correspondent pas !" << std::endl;

    return 0;
}
