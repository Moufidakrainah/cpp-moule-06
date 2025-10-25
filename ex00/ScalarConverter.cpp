/* la methode statique convert prendra en parametre 
une chaine de caractere std::string contiendra 
un litteral (valeurs directement ecrite dans code)
exp : int a = 42; 42 est un litteral entier.
Le programme doit determiner de quel type est cette valeur.*/

#include "ScalarConverter.hpp"
 
/* verifie si la chaine s a exactement un caractere et ce n est pas un chiffre*/
static bool isCharLiteral(const std::string &s) {
    return s.length() == 1 && !std::isdigit(s[0]);
}

/*verifie si toute la chaine est compose de chiffres*/
static bool isIntLiteral(const std::string &s) {
    size_t i = 0;
    if (s[i] == '+' || s[i] == '-') i++;
    for (; i < s.length(); i++) {
        if (!std::isdigit(s[i])) return false;
    }
    return true;
}
/* verifie si la chaine finit par un f, contient un point,
 et tous les auttres sont des chiffres "float standard"
 nan : not a number double (resultat d'operation infefinies)
 inf : infini double
 nanf: not a number float
 inff infini float
 dans notre exercice quand on passe nanf et inff  ScalarConverter
 la conversion en char et int est impossible*/
 
static bool isFloatLiteral(const std::string &s) {
    if (s == "-inff" || s == "+inff" || s == "nanf")
        return true;
    bool hasDot = false;
    if (s[s.length() - 1] != 'f') return false;
    size_t i = (s[0] == '+' || s[0] == '-') ? 1 : 0;
    for (; i < s.length() - 1; i++) {
        if (s[i] == '.') {
            if (hasDot) return false;
            hasDot = true;
        } else if (!std::isdigit(s[i]))
            return false;
    }
    return hasDot;
}

static bool isDoubleLiteral(const std::string &s) {
    if (s == "-inf" || s == "+inf" || s == "nan")
        return true;
    bool hasDot = false;
    size_t i = (s[0] == '+' || s[0] == '-') ? 1 : 0;
    for (; i < s.length(); i++) {
        if (s[i] == '.') {
            if (hasDot) return false;
            hasDot = true;
        } else if (!std::isdigit(s[i]))
            return false;
    }
    return hasDot;
}

void ScalarConverter::convert(const std::string &literal) {
    std::cout.setf(std::ios::fixed);
    std::cout.precision(1);

    // === CHAR ===
    if (isCharLiteral(literal)) {
        char c = literal[0];
        std::cout << "char: '" << c << "'\n";
        std::cout << "int: " << static_cast<int>(c) << "\n";
        std::cout << "float: " << static_cast<float>(c) << "f\n";
        std::cout << "double: " << static_cast<double>(c) << "\n";
        return;
    }

    // === INT ===
    if (isIntLiteral(literal)) {
        long num = std::strtol(literal.c_str(), NULL, 10);
        if (num < INT_MIN || num > INT_MAX) {
            std::cout << "char: impossible\n";
            std::cout << "int: overflow\n";
            std::cout << "float: impossible\n";
            std::cout << "double: impossible\n";
            return;
        }
        int value = static_cast<int>(num);
        if (std::isprint(value))
            std::cout << "char: '" << static_cast<char>(value) << "'\n";
        else
            std::cout << "char: Non displayable\n";
        std::cout << "int: " << value << "\n";
        std::cout << "float: " << static_cast<float>(value) << "f\n";
        std::cout << "double: " << static_cast<double>(value) << "\n";
        return;
    }

    // === FLOAT ===
    if (isFloatLiteral(literal)) {
        float f = std::strtof(literal.c_str(), NULL);
        if (std::isnan(f) || std::isinf(f)) {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
        } else {
            if (std::isprint(static_cast<int>(f)))
                std::cout << "char: '" << static_cast<char>(f) << "'\n";
            else
                std::cout << "char: Non displayable\n";
            std::cout << "int: " << static_cast<int>(f) << "\n";
        }
        std::cout << "float: " << f << "f\n";
        std::cout << "double: " << static_cast<double>(f) << "\n";
        return;
    }

    // === DOUBLE ===
    if (isDoubleLiteral(literal)) {
        double d = std::strtod(literal.c_str(), NULL);
        if (std::isnan(d) || std::isinf(d)) {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
        } else {
            if (std::isprint(static_cast<int>(d)))
                std::cout << "char: '" << static_cast<char>(d) << "'\n";
            else
                std::cout << "char: Non displayable\n";
            std::cout << "int: " << static_cast<int>(d) << "\n";
        }
        std::cout << "float: " << static_cast<float>(d) << "f\n";
        std::cout << "double: " << d << "\n";
        return;
    }

    // === ERREUR ===
    std::cout << "Error: invalid literal\n";
}