#include "Serializer.hpp"

/* Serialisation : convertir un objet (ici un pointeur data*) en une representation binaire simple (un entiet uintptr_t)
uintptr_t est un type entier non signe (unsigned integer), assez grand pour stocker une adresse memoire (pointeur), son role principal est de convertir un pointeur en entier et vice_versa.*/

Serializer::Serializer() {}
Serializer::Serializer(const Serializer &other) { 
    (void)other; 
}
Serializer &Serializer::operator=(const Serializer &other) {
    (void)other;
    return *this;
}
Serializer::~Serializer() {}


/* Sérialisation */
uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

/*Désérialisation */
Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
