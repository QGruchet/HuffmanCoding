#include "Tree.hpp"

/* Builders */
// Default
Sommet::Sommet() : numCar(-1), car('\0'), left(nullptr), right(nullptr) {}
ArbreB::ArbreB() : root(nullptr), depth(0), size(0) {}
// End default

ArbreB::ArbreB(Sommet *newRoot) {
    root = newRoot;
    depth = newRoot->getDepth();
    size = 0;
}

void Sommet::init(int newNumCar, char newCar) {
    if(newNumCar >= 0) {
        numCar = newNumCar;
        car = newCar;

        left = nullptr;
        right = nullptr;
    }
    else {
        std::cout << "ERROR : invalid newNumCar, call default builder" << std::endl;

        numCar = 0;
        car = '\0';

        left = nullptr;
        right = nullptr;
    }
}

Sommet::Sommet(int newNumCar, char newCar) {
    init(newNumCar, newCar);
}

Sommet::Sommet(int newNum) {
    init(newNum, '\0');
}
/* End builders */

/* Overloaded */
// Operator=
// End operator=

// Operator<<
Sommet& Sommet::operator<<(int newData) {
    if(numCar >= newData) {
      if(left) {
        *left << newData;
      }
      else{
        left = new Sommet(newData);
      }
    }
    else{
      if(right) {
        *right << newData;
      }
      else {
        right = new Sommet(newData);
      }
    }
    return *this;
}

std::ostream &operator<<(std::ostream &flux, const Sommet *other) {
    if(other->getCar() == '\0') {
        flux << other->getNumCar();
    }
    return flux;
}

std::ostream &operator<<(std::ostream &flux, Sommet s) {
    flux << "Prefix : \n";
    s.printPrefix();

    return flux;
}
// End operator<<

// Operator+=, operator-=
// End operator+=, operator-=

// Operator[]
// End operator[]
/* End overloaded */

/* Getters */
int Sommet::getNumCar() const {
    return this->numCar;
}

char Sommet::getCar() const {
    return this->car;
}

Sommet* Sommet::getLeft() const {
    return left;
}

Sommet* Sommet::getRight() const {
    return right;
}

Sommet* ArbreB::getRoot() const {
    return root;
}

int Sommet::getDepth() {
    int depthLeft = 0, depthRight = 0;
    if(left) {
        depthLeft = left->getDepth();
    }
    else if(right) {
        depthRight = right->getDepth();
    }
    return 1 + maximum(depthLeft, depthRight);
}

int ArbreB::getSize() const {
    return this->size;
}
/* End getters */

/* Methodes */
int Sommet::maximum(int a, int b){
    return (a > b) ? a : b;
}

bool ArbreB::isTreeEmpty() {
    return !(root);
}

bool Sommet::isLeaf() {
    return (!left && !right);
}

void Sommet::printPrefix() {
    std::cout << numCar << ", ";
    left->printPrefix();
    right->printPrefix();
}

void Sommet::printBeautifulTree(int space) {
    if(right) {
        right->printBeautifulTree(space + 1);
    }
    for(int i = 0; i < space; i++) {
        printf("   ");
    }
    std::cout << this->numCar << std::endl;
    if(left) {
        left->printBeautifulTree(space + 1);
    }
}

void Sommet::clean() {
    if(left) {
        left->clean();
    }
    if(right) {
        right->clean();
    }

    delete this;
}
/* End printers */

void Sommet::ecritureHeader(){
    //Si le fichier existe on le supprime cela evite d'ecrire deux fois dans un meme fichier
    if(std::ifstream("src/out/binary_tree.dot")){
        remove("src/out/binary_tree.dot");
        std::cout << "Suppression de binary_tree.dot" << std::endl;
    }
    //On creer le fichier
    std::string const nomFichier("binary_tree.dot");
    std::ofstream flux(nomFichier.c_str(), std::ios_base::app);

    if(flux){
        flux << "digraph{" << std::endl;
    }
}

void Sommet::ecritureFichier(Sommet *node){
    std::string const nomFichier("binary_tree.dot");
    std::ofstream flux(nomFichier.c_str(), std::ios_base::app);

    if(flux){
        if(!node){
            return;
        }
        else{
            if(node->left){
                flux << node << "->" << std::endl;
            }
            else{
                flux << node << std::endl;
            }
            ecritureFichier(node->left);
            if(node->right){
                flux << node << "->" << std::endl;
            }
            else{
                flux << node << std::endl;
            }
            ecritureFichier(node->right);
        }
    }
    else{
        std::cout << "Error : opening file";
    }
}

void Sommet::ecritureEnder(){
    std::string const nomFichier("binary_tree.dot");
    std::ofstream flux(nomFichier.c_str(), std::ios_base::app);

    if(flux){
        flux << "}" << std::endl;
    }
}

/* Destructors */
Sommet::~Sommet() {}
ArbreB::~ArbreB() {
    if(root) {
        root->clean();
    }
}
/* End destructors */