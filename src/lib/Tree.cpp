/**
 * Tree.cpp : You can found here all functions implemented for the Tree class.
 * Author : Mickael.
 * */
#include "Tree.hpp"

/**
 * Function : Constructor by copy.
 * Return : 'Sommet'.
 * Description : Create an object 'Sommet' with default parameters.
 * */
Sommet::Sommet() : data(0), left(nullptr), right(nullptr) {}

/**
 * Function : Constructor by copy.
 * Return : 'ArbreB'.
 * Description : Create an object 'ArbreB' with default parameters.
 * */
ArbreB::ArbreB() : root(nullptr)  {}

/**
 * Function : Copy.
 * Return : 'Sommet'*.
 * Description : Return a deep copy of this.
 * */
Sommet* Sommet::copy() {
    Sommet *newNode = new Sommet(data);
    if(left) {
        newNode->left = left->copy();
    }
    if(right) {
        newNode->right = right->copy();
    }
    return newNode;
}

/**
 * Function : Constructor by copy.
 * Return : 'Sommet'.
 * Description : Create an object 'Sommet' with an other.
 * */
Sommet::Sommet(const Sommet& other) {
    data = other.data;
    left = nullptr;
    if(other.left) {
        left = other.left->copy();
    }
    right = nullptr;
    if(other.right) {
        right = other.right->copy();
    }
}

/** Function : Constructor by copy.
 * Return : 'ArbreB'.
 * Description : Create a object 'ArbreB' with an other.
 * */
ArbreB::ArbreB(const ArbreB& other) {
    root = new Sommet;
    *root = *other.root;
}

/** Function : Constructor with parameter.
 * Return : 'Sommet'.
 * Description : Create a object 'Sommet' by initializing the data.
 * */
Sommet::Sommet(int newData) : data(newData), left(nullptr), right(nullptr) {}

/** Function : Constructor with parameter.
 * Return : 'ArbreB'.
 * Description : Create a object 'ArbreB' by initializing the root.
 * */
ArbreB::ArbreB(int rootData) {
    root = new Sommet(rootData);
}

/** Function : Overloading operator=.
 * Return : 'Sommet'.
 * Description : Copy a object 'Sommet' with an other.
 * */
Sommet& Sommet::operator=(Sommet other) {
    if(this != &other) {
        data = other.data;
        if(other.left) {
            left = other.left->copy();
        }
        if(other.right) {
            right = other.right->copy();
        }
    }
    return *this;
}

/** Function : Overloading operator=.
 * Return : 'ArbreB'.
 * Description : Swap the value of the 'Sommet' with newData.
 * */
Sommet& Sommet::operator=(int newData) {
    data = newData;
    return *this;
}


/** Function : Overloading operator=.
 * Return : 'ArbreB'.
 * Description : Copy a object 'ArbreB' with an other.
 * */
ArbreB& ArbreB::operator=(const ArbreB& other) {
    if(this != &other) {
        if(!root) {
            root = new Sommet(other.root->data);
        }
        *root = *other.root;
    }
    return *this;
}

/** Function : Overloading operator==.
 * Return : boolean.
 * Description : Say if the 'Sommet' is equal to an other.
 * */
bool Sommet::operator==(const Sommet& other) {
    if(data == other.data) {
        if(left && other.left) {
            if(!left->equal(other.left)) {
                return false;
            }
        }
        if(right && other.right) {
            return right->equal(other.right);
        }
        if(!left && !right) {
            return true;
        }
    }
    return false;
}

/** Function : Overloading operator==.
 * Return : boolean.
 * Description : Say if the 'Sommet' is equal to an other, recursive version.
 * */
bool Sommet::equal(Sommet *node) {
    if(node) {
        if(data != node->data) {
            return false;
        }
        if(left && node->left) {
            if(!left->equal(node->left)) {
                return false;
            }
        }
        if(right && node->right) {
            return right->equal(node->right);
        }
    }
    return true;
}


/** Function : Overloading operator==.
 * Return : boolean.
 * Description : Say if the 'ArbreB' is equal to an other.
 * */
bool ArbreB::operator==(const ArbreB& other) {
    if(!root && !other.root) { // Two empty trees is always equal
        return true;
    }
    if((!root && other.root) || (root && !other.root)) {
        return false;
    }
    return *root == *other.root;
}

/** Function : Overloading operator<<.
 * Return : 'ArbreB'.
 * Description : Add a node with the value 'newData' in the tree.
 * */
ArbreB& ArbreB::operator<<(int newData) {
    if(!root) {
        root = new Sommet(newData);
    }
    else {
        add(root, newData); // Call recursive function
    }
    return *this;
}

/** Function : add.
 * Return : 'ArbreB'.
 * Description : Add a node with the value 'newData' in the tree, recursive version.
 * */
void ArbreB::add(Sommet *root, int newData) {
    if(rand()%2) { // Add randomly the new root 
        if(root->left) {
            add(root->left, newData);
        }
        else {
            root->left = new Sommet(newData);
        }
    }
    else {
        if(root->right) {
            add(root->right, newData);
        }
        else {
            root->right = new Sommet(newData);
        }
    }
}

/** Function : Overloading operator>>.
 * Return : 'ArbreB'.
 * Description : Dell a node with the value 'dellData' in the tree, if
 * the node with 'dellData' existe.
 * */
ArbreB& ArbreB::operator>>(int dellData) {
    Sommet *dellNode = find(root, dellData);
    if(!dellNode || !root) { // If haven't root or the value dellData wasen't found
        return *this;
    }
    if(root->data == dellData) {
        if(root->isLeaf()) {
            delete root;
            root = nullptr;
        }
        else {
            Sommet *randLeaf = getRandLeaf(root);
            int swap = randLeaf->data;
            randLeaf->data = root->data;
            root->data = swap;

            dell(root, dellData);
        }
        return *this;
    }

    dell(root, dellData);
    return *this;
}

/** Function : dell.
 * Return : 'ArbreB'.
 * Description : Dell a node with the value 'dellData' in the tree, if
 * the node with 'dellData' existe, recursive version.
 * */
void ArbreB::dell(Sommet *root, int dellData) {
    if(!root) {
        return;
    }
    if(root->left) {
        if(root->left->data == dellData) {
            if(root->left->isLeaf()) {
                delete root->left;
                root->left = nullptr;
                return;
            }
        //   else{
        //     Sommet *randLeaf = getRandLeaf(root->left);
        //     int swap = randLeaf->data;
        //     randLeaf->data = root->left->data;
        //     root->left->data = swap;

        //     dell(root->left, dellData);
        //   }
        }
        // else {
        //   dell(root->left, dellData);
        // }
    }
    if(root->right) {
        if(root->right->data == dellData) {
            if(root->right->isLeaf()) {
                delete root->right;
                root->right = nullptr;
                return;
            }
        // else{
        //   Sommet *randLeaf = getRandLeaf(root->right);
        //   int swap = randLeaf->data;
        //   randLeaf->data = root->right->data;
        //   root->right->data = swap;

        //   dell(root->right, dellData);
        // }
        }
        // else {
        //   dell(root->right, dellData);
        // }
    }
}

std::ostream &operator<<(std::ostream &flux, const Sommet& node) {
    flux << node.data << ", ";
    if(node.left) {
        flux << *node.left;
    }
    if(node.right) {
        flux << *node.right;
    }
    return flux;
}

std::ostream &operator<<(std::ostream &flux, const ArbreB& tree) {
    if(tree.root) {
        flux << *tree.root;
    }
    return flux;
}
// End operator<<

// Operator+=, operator-=
ArbreB& ArbreB::operator+=(const ArbreB& other) {
    Sommet *cpyOther = other.root->copy();
    
    Sommet *newRoot = new Sommet(root->data + cpyOther->data);
    newRoot->left = root;
    newRoot->right = cpyOther;

    root = newRoot;

    return *this;
}

ArbreB& ArbreB::operator-=(ArbreB& other) {
    if(root && root->left && root->right) {
        other.root = root->right;
        Sommet *oldRoot = root;
        root = root->left;
        oldRoot->left = oldRoot->right = nullptr;
        delete oldRoot;
    }

    return *this;
}
// End operator+=, operator-=

// Operator[]
Sommet* ArbreB::operator[](int index) {
    index--;
    if(index < 0 || index >= root->countSize()) {
        std::cout << "ERROR : index out of band" << std::endl;
        return nullptr;
    }
    else if(index == 0) {
        return root;
    }

    // Breadth First Search (BFS)
    int posNodeInTree = 0;
    std::queue<Sommet*> queue;
    queue.push(root);
    Sommet* start;
    posNodeInTree++;

    while(!queue.empty()) {
        start = queue.front();
        queue.pop();
        
        if(start->left) {
            if(index == posNodeInTree) {
                return start->left;
            }
            posNodeInTree++;
            
            queue.push(start->left);
        }

        if(start->right) {
            if(index == posNodeInTree) {
                return start->right;
            }
            posNodeInTree++;

            queue.push(start->right);
        }
    }

    return nullptr;
}

Sommet* ArbreB::find(Sommet* root, int dataSearch) {
    if(root) {
        if(root->data == dataSearch) {
            return root;
        }
        if(root->left) {
            Sommet* ret = find(root->left, dataSearch);
            if(ret) {
                return ret;
            }
        }
        if(root->right) {
            return find(root->right, dataSearch);
        }
    }

    return nullptr;
}
// End operator[]
/* End overloaded */

/* Getters */
int Sommet::getData() const {
    return data;
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

Sommet* ArbreB::getRandLeaf(Sommet* root) const{
    if(!root) {
        return nullptr;
    }
    if(root->isLeaf()) {
        return root;
    }
    if(root->left) {
        return getRandLeaf(root->left);
    }
    if(root->right) {
        return getRandLeaf(root->right);
    }

    return nullptr;
}
/* End getters */

/* Setters */
void Sommet::setLeft(int leftData) {
    if(left) {
        left->data = leftData;
    }
    else {
        left = new Sommet(leftData);
    }
}

void Sommet::setRight(int rightData) {
    if(right) {
        right->data = rightData;
    }
    else {
        right = new Sommet(rightData);
    }
}
/* End setters */

/* Methodes */
void Sommet::Min(int *min) {
    if(data <= *min) {
        *min = data;
    }
    if(left) {
        left->Min(min);
    }
    if(right) {
        right->Min(min);
    }
}

int Sommet::dataMin() {
    int min = INT32_MAX; // Init min with the max value for int
    Min(&min);
    return min;
}

void Sommet::Max(int *max) {
    if(data >= *max) {
        *max = data;
    }
    if(left) {
        left->Max(max);
    }
    if(right) {
        right->Max(max);
    }
}

int Sommet::dataMax() {
    int max = INT32_MIN; // Init min with the min value for int
    Max(&max);
    return max;
}

bool Sommet::isLeaf() {
    return (!left && !right);
}

void Sommet::printBeautifulTree(int space) {
    if(right) {
        right->printBeautifulTree(space + 1);
    }
    for(int i = 0; i < space; i++) {
        std::cout << "   ";
    }
    std::cout << this->data << std::endl;
    if(left) {
        left->printBeautifulTree(space + 1);
    }
}

int maximum(int a, int b){
    return (a > b) ? a : b;
}

int Sommet::countDepth() {
    int depthLeft = 0, depthRight = 0;
    if(left) {
        depthLeft = left->countDepth();
    }
    if(right) {
        depthRight = right->countDepth();
    }
    return 1 + maximum(depthLeft, depthRight);
}

int Sommet::countSize() {
    int countLeft = 0, countRight = 0;
    if(left) {
        countLeft = left->countSize();
    }
    if(right) {
        countRight = right->countSize();
    }
    return 1 + countLeft + countRight;
}
/* End printers */

/* Destructors */
Sommet::~Sommet() {
    if(left) {
        delete left;
    }
    if(right) {
        delete right;
    }
}
ArbreB::~ArbreB() {
    if(root) {
        delete root;
    }
    root = nullptr;
}
/* End destructors */