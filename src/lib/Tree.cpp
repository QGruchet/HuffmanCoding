#include "Tree.hpp"

/* Builders */
// Default
Sommet::Sommet() : numCar(-1), car('\0'), left(nullptr), right(nullptr) {}
ArbreB::ArbreB() : root(nullptr), depth(0), size(0) {}
// End default

ArbreB::ArbreB(Sommet *root) {
    this->root = root;
    this->depth = getDepth(root);
    this->size = 0;
}

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
/* End builders */

/* Overloaded */
// Operator=
// ArbreB& ArbreB::operator=(ArbreB &other) {
//     return *this;
// }
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

// std::ostream &operator<<(std::ostream &flux, const ArbreB &other) {
//     return flux;
// } 
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
// Sommet* ArbreB::operator[](int index) {
//     if(index-1 < 0 || index-1 >= this->size) {
//         std::cout << "ERROR : index out of band." << std::endl;
//         return nullptr;
//     }

//     std::queue<Sommet> queueTree;
//     this->toQueue(&queueTree);
//     int posInQueue = 0;
//     while(posInQueue<index-1) {
//         queueTree.pop();
//         posInQueue++;
//     }
    
//     return &(queueTree.front());
// }
// End operator[]

// Operator<, operator>
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

int ArbreB::getDepth(Sommet *node) {
    if(!node) {
        return 0;
    }
    else if(node == this->root) {
        return maximum(getDepth(node->getLeft()), getDepth(node->getRight()));
    }
    else {
        return 1 + maximum(getDepth(node->getLeft()), getDepth(node->getRight()));
    }
}

int ArbreB::getSize() const {
    return this->size;
}
/* End getters */

/* Methodes */
void Sommet::add(Sommet *root, int newData) {
    if(!root) {
        root = new Sommet(newData);
        return;
    }

    if(!root->left && root->numCar >= newData) {
        root->left = new Sommet(newData);
        return;
    }
    else if(!root->right && root->numCar < newData) {
        root->right = new Sommet(newData);
        return;
    }

    if(root->numCar >= newData) {
        add(root->left, newData);
    }
    else{
        add(root->right, newData);
    }
}

int ArbreB::maximum(int a, int b){
    return (a > b) ? a : b;
}

bool ArbreB::isTreeEmpty() {
    return !(this->root);
}

bool Sommet::isLeaf() {
    return (!this->left && !this->right);
}

// void ArbreB::toQueue(std::queue<Sommet> *queueTree) {
//     std::queue<Sommet> fifo;
//     fifo.push(*this->root);

//     while(!fifo.empty()) {
//         Sommet last = fifo.front();
//         fifo.pop();

//         (*queueTree).push(last);
//         if(last.left) {
//             fifo.push(*last.left);
//         }
//         if(last.right) {
//             fifo.push(*last.right);
//         }
//     }
// }
void Sommet::print(Sommet *node) {
    if(!node) {
        std::cout << "Empty tree" << std::endl;
        return;
    }
    std::cout << "Prefix : " << std::endl;
    printPrefix(node);
    std::cout << "\n";
}

void Sommet::printPrefix(Sommet *node) {
    if(!node) {
        return;
    }
    
    std::cout << node->numCar << ", ";
    printPrefix(node->left);
    printPrefix(node->right);
}

void Sommet::printTree(Sommet *node, int space) {
    if(!node) {
        return;
    }
    else {
        printTree(node->right, space + 1);  
        for(int i = 0; i < space; i++) {
            printf("   ");
        }
        std::cout << *node << std::endl;
        printTree(node->left, space + 1);
    }
}

void Sommet::clean(Sommet *node) {
    if(!node) {
        return;
    }

    clean(node->left);
    clean(node->right);

    delete node;
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
                flux << *node << "->" << std::endl;
            }
            else{
                flux << *node << std::endl;
            }
            ecritureFichier(node->left);
            if(node->right){
                flux << *node << "->" << std::endl;
            }
            else{
                flux << *node << std::endl;
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
    this->root->clean(this->root);
}
/* End destructors */