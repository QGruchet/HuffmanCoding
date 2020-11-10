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
    if(other.getCar() == '\0') {
        flux << other.getNumCar();
    }
    else {
        flux << other.getNumCar() << ", " << other.getCar();
    }
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
void ArbreB::operator<(Sommet newNode) {
    return;
}

int ArbreB::emptyTree() {
    return (this->root == nullptr);
}

void ArbreB::addNode(Sommet *newNode, Sommet *root) {
    if(this->emptyTree()){
        this->root = newNode;
        return;
    }
    else if(!root->left && newNode->getNumCar() <= root->getNumCar()) {
        root->left = new Sommet(newNode->getNumCar(), newNode->getCar());
    }
    else if(!root->right && newNode->getNumCar() >= root->getNumCar()) {
        root->right = new Sommet(newNode->getNumCar(), newNode->getCar());
    }
    else{
        if(newNode->getCar() <= root->getCar()){
            return addNode(newNode, root->getLeft());
        }
        else {
            return addNode(newNode, root->getRight());
        }
    }
}

void ArbreB::operator>(Sommet* newRoot) {
    return;
}

// friend std::ostream &operator<<(std::ostream &flux, const Arbre& tree)
void ArbreB::printTree(Sommet *sommet, int space) {
    if(!sommet) {
        return;
    }
    else {
        printTree(sommet->getRight(), space + 1);
        for(int i = 0; i < space; i++) {
            printf("   ");
        }
        std::cout << *sommet << std::endl;
        printTree(sommet->getLeft(), space + 1);
    }
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

/* Methodes */
int ArbreB::maximum(int a, int b){
    return (a > b) ? a : b;
}

int ArbreB::getDepth(Sommet *sommet){
    if(!sommet){
        return 0;
    }
    else{
            return 1 + maximum(getDepth(sommet->getLeft()), getDepth(sommet->getRight()));
    }
}

/* End printers */

/* Destructors */
Sommet::~Sommet() {}
ArbreB::~ArbreB() {}
/* End destructors */