#include "Tree.hpp"

/* Builders */
// Default
Sommet::Sommet() : numCar(-1), car('\0'), left(nullptr), right(nullptr) {}
ArbreB::ArbreB() : root(nullptr), depth(0), size(0) {}
// End default

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
void ArbreB::copy(Sommet *node, Sommet *nodeCopy) {
    if(!node) {
        return;
    }
    if(node->isLeaf()) {
        nodeCopy = new Sommet(node->numCar, node->car);
        this->size += 1;
    }

    copy(node->left, nodeCopy->left);
    copy(node->right, nodeCopy->right);
}

ArbreB& ArbreB::operator=(ArbreB &other) {
    if(this != &other) {
        this->root = new Sommet(other.root->numCar, other.root->car);
        this->size = 0;
        this->depth = this->getDepth(this->root);
        copy(other.root, this->root);
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
Sommet* ArbreB::operator[](int index) {
    if(index-1 < 0 || index-1 >= this->size) {
        std::cout << "ERROR : index out of band." << std::endl;
        return nullptr;
    }

    std::queue<Sommet> queueTree;
    this->toQueue(&queueTree);
    int posInQueue = 0;
    while(posInQueue<index-1) {
        queueTree.pop();
        posInQueue++;
    }
    
    return &(queueTree.front());
}
// End operator[]

// Operator<, operator>
void ArbreB::operator<(Sommet newNode) {
    addNode(this->root, &newNode);
}

void ArbreB::operator>(int index) {
    if(0 > index-1 || index-1 >= this->size ) {
        std::cout << "ERROR : index out of range" << std::endl;
        return;
    }

    std::queue<Sommet> queueTree;
    this->toQueue(&queueTree);
    Sommet *root = &queueTree.front();
    ArbreB tree(root);
    queueTree.pop();
    int tmp = 1;
    while(!queueTree.empty()) {
        if(tmp!=index-1) {
            tree < queueTree.front();
        }
        queueTree.pop();
        tmp++;
    }

    *this = tree;
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

bool Sommet::isLeaf() {
    return (!this->left && !this->right);
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

void ArbreB::toQueue(std::queue<Sommet> *queueTree) {
    std::queue<Sommet*> fifo;
    fifo.push(this->root);

    while(!fifo.empty()) {
        Sommet *last = fifo.front();
        fifo.pop();

        (*queueTree).push(*last);
        if(last->left) {
            fifo.push(last->left);
        }
        if(last->right) {
            fifo.push(last->right);
        }
    }
}

void ArbreB::printTree(Sommet *node, int space) {
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

void ArbreB::clear(Sommet **node) {
    Sommet *tmpNode = *node;

    if(!node) return;

    if(tmpNode->left)  clear(&tmpNode->left);
    if(tmpNode->right) clear(&tmpNode->right);

    delete tmpNode; 
    *node = NULL;
}
/* End printers */

/* Destructors */
Sommet::~Sommet() {}
ArbreB::~ArbreB() {
    if(this->root) {
        this->clear(&this->root);
        delete this->root;
    }
}
/* End destructors */