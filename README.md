# cpp module 06 : Les cast
1- static_cast : conversions standards, compatibles, et verifiees a la compilation 
Utilisation typique:
conversion entre types numeriques (int, float, double..).
conversion entre type parents et enfants dans une hierarchie de classes.
conversion explicite quand le copilateur ne le fait pas automatiquement.

2- dynamic_cast : Utilise uniquement avec les pointeurs ou references sur des classes polymorphes ( c'est a dire avec au moins une methode virtual ).
il permet de convertir en toute securite un pointeur vers une classe de base vers un pointeur vers une classe derivees, en verifiant a l'execution que c'est valide.
exp:
class Base { public: virtual ~Base() {} };
class Derived : public Base {};

Base *b = new Derived();
Derived *d = dynamic_cast<Derived*>(b);

si la conversion ehoue dynamic_cast renvoie nullptr pour les pointeurs

3- reinterpret_cast: sert a reinterpreter les bits d'un objet comme un autre type, aucune verification est faite
exp:
int n = 65;
char *p = reinterpret_cast<char*>(&n);
std::cout << *p; // interprète les bits de l’int comme un char
 
