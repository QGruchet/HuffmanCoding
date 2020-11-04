#include "Tree.hpp"

/* Builders */
// Default
Sommet::Sommet() : numCar(0), car('\0'), left(nullptr), right(nullptr) {}
ArbreB::ArbreB() : root(nullptr) {}
// End default

// Copy
Sommet::Sommet(const Sommet &other) {
    this->numCar = other.numCar;
    this->car = other.car;

    this->left = other.left;
    this->right = other.right;
}

ArbreB::ArbreB(const ArbreB &other) {
    this->root = other.root;
}
// End copy

Sommet::Sommet(int numCar, char car) {
    if( numCar >= 0) {
        this->numCar = numCar;
        this->car = car;

        this->left = nullptr;
        this->right = nullptr;
    }
    else {
        std::cout << "ERROR : invalid numCar, call default builder" << std::endl;

        this->numCar = 0;
        this->car = '\0';

        this->left = nullptr;
        this->right = nullptr;
    }
}

ArbreB::ArbreB(Sommet* root) {
    this->root = root;
}
/* End builders */

/* Overloaded */
// Operator=
Sommet& Sommet::operator=(const Sommet &other) {
    if( this != &other) {
        this->numCar = other.numCar;
        this->car = other.car;

        this->left = other.left;
        this->right = other.right;
    }

    return *this;
}
ArbreB& ArbreB::operator=(const ArbreB &other) {
    if(this != &other) {
        this->root = other.root;
    }

    return *this;
}
// End operator=

// Operator<<
std::ostream &operator<<(std::ostream &flux, const Sommet &other) {
    flux << other.getNumCar() << ", " << other.getCar();
    return flux;
}
// End operator<<

// Operator+=, operator-=
// ArbreB& ArbreB::operator+=(const ArbreB &other) {
//     /* Not implemented yet */
// }

// ArbreB& ArbreB::operator-=(const ArbreB &other) {
//     /* Not implemented yet */
// }
// End operator+=, operator-=

// Operator[]
// Sommet& ArbreB::operator[](int index) {
//     /* Not implemented yet */
// }
// End operator[]

// Operator<, operator>
void ArbreB::operator<(const Sommet&) {
    return;
}

int ArbreB::operator>(Sommet&) {
    return 0;
}
// End Operator<, operator>

/* End overloaded */

/* Getters */
int Sommet::getNumCar() const {
    return this->numCar;
}

char Sommet::getCar() const {
    return this->car;
}

Sommet* Sommet::getLeft() const {
    return this->left;
}

Sommet* Sommet::getRight() const {
    return this->right;
}

Sommet* ArbreB::getRoot() const {
    return this->root;
}
/* End getters */

/* Destructors */
Sommet::~Sommet() {}
ArbreB::~ArbreB() {}
/* End destructors */