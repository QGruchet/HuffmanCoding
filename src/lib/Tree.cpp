#include "Tree.hpp"

/* Builders */
// Default
Sommet::Sommet() : numCar(-1), car('\0'), left(nullptr), right(nullptr) {}
ArbreB::ArbreB() : root(nullptr), depth(0), size(0) {}
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
    this->depth = other.depth;
    this->size = other.size;
}
// End copy

void Sommet::init(int numCar, char car) {
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

Sommet::Sommet(int numCar, char car) {
    init(numCar, car);
}

Sommet::Sommet(int num) {
    init(num, '\0');
}

ArbreB::ArbreB(Sommet* root) {
    this->root = root;
    this->depth = 0;
    this->size = 1;
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
        this->depth = other.depth;
        this->size = other.size;
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
Sommet* ArbreB::operator[](int index) {
    if(index-1 < 0 || index-1 >= this->size) {
        std::cout << "ERROR : index out of band." << std::endl;
        return nullptr;
    }

    std::vector<Sommet*> vector;
    this->toVector(vector);
    return vector.at(index-1);
}
// End operator[]

// Operator<, operator>
void ArbreB::operator<(Sommet newNode) {
    addNode(this->root, &newNode);
}

void ArbreB::operator>(Sommet* newRoot) {
    return;
}

// std::ostream &operator<<(std::ostream &flux, const ArbreB &other) {
//     flux << "size : " << other.getSize() << ", depth : " << other.getDepth(other.getRoot());
//     other.printTree(other.getRoot(), 0);
//     return flux;
// } 
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

int ArbreB::getDepth(Sommet *sommet) {
    if(!sommet) {
        return 0;
    }
    else if(sommet == this->root) {
        return maximum(getDepth(sommet->getLeft()), getDepth(sommet->getRight()));
    }
    else {
        return 1 + maximum(getDepth(sommet->getLeft()), getDepth(sommet->getRight()));
    }
}

int ArbreB::getSize() const {
    return this->size;
}
/* End getters */

/* Methodes */
int ArbreB::maximum(int a, int b){
    return (a > b) ? a : b;
}

bool ArbreB::isTreeEmpty() {
    return (this->root == nullptr);
}

void ArbreB::addNode(Sommet *root, Sommet *newNode) {
    if(this->isTreeEmpty()){
        this->root = newNode;
        return;
    }
    else if(!root->left && newNode->numCar <= root->numCar) {
        this->size += 1;
        root->left = new Sommet(newNode->numCar, newNode->car);
    }
    else if(!root->right && newNode->numCar >= root->numCar) {
        this->size += 1;
        root->right = new Sommet(newNode->numCar, newNode->car);
    }
    else{
        if(newNode->numCar <= root->numCar){
            return addNode(root->left, newNode);
        }
        else {
            return addNode(root->right, newNode);
        }
    }
}

void ArbreB::toVector(std::vector<Sommet*> vectorTree) {
    std::vector<Sommet*> fifo;
    fifo.reserve(this->size);
    fifo.push_back(this->root);

    vectorTree.reserve(this->size);

    while(!fifo.empty()) {
        Sommet *last = fifo.back();
        fifo.pop_back();

        if(last) {
            vectorTree.push_back(last);
            fifo.push_back(last->left);
            fifo.push_back(last->right);
        }
    }
}

void ArbreB::printTree(Sommet *sommet, int space) {
    if(!sommet) {
        return;
    }
    else {
        printTree(sommet->right, space + 1);
        for(int i = 0; i < space; i++) {
            printf("   ");
        }
        std::cout << *sommet << std::endl;
        printTree(sommet->left, space + 1);
    }
}
/* End printers */

/* Destructors */
Sommet::~Sommet() {}
ArbreB::~ArbreB() {}
/* End destructors */