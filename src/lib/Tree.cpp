/**
 * Tree.cpp : You can found here all functions implemented for the Tree class.
 * Author : Mickael.
 * */
#include "Tree.hpp"

/**
 * Function : Constructor by default.
 * Return : 'Sommet'.
 * Description : Create an object 'Sommet' with default parameters.
 * */
Sommet::Sommet() {
    data.freq = 0;
    data.car = '\0';
    left = nullptr;
    right = nullptr;
}

/**
 * Function : Constructor by default.
 * Return : 'ArbreB'.
 * Description : Create an object 'ArbreB' with default parameters.
 * */
ArbreB::ArbreB() : root(nullptr)  {}

/**
 * Function : Copy.
 * Return : 'Sommet*'.
 * Description : Return a deep copy of the current object.
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
 * Parameter : other, the other node for the copy.
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
 * Parameter : other, the other tree for the copy.
 * Description : Create a object 'ArbreB' with an other.
 * */
ArbreB::ArbreB(const ArbreB& other) {
    root = new Sommet;
    *root = *other.root;
}

/** Function : Constructor with parameter.
 * Return : 'Sommet'.
 * Paramter : newData, the data to init the node.
 * Description : Create a object 'Sommet' by initializing the data.
 * */
Sommet::Sommet(int newData, char newCar) {
    data.freq = newData;
    data.car = newCar;
    left = nullptr;
    right = nullptr;
}

Sommet::Sommet(Data newData) : data(newData), left(nullptr), right(nullptr) {}

/** Function : Constructor with parameter.
 * Return : 'ArbreB'.
 * Parameter : rootData, tha data to init the root of the tree.
 * Description : Create a object 'ArbreB' by initializing the root.
 * */
ArbreB::ArbreB(int rootData, char charRoot) {
    root = new Sommet(rootData, charRoot);
}

/** Function : Overloading operator=.
 * Return : 'Sommet'.
 * Parameter : other, the node for the copy.
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
 * Parameter : newData, the data for swap.
 * Description : Swap the value of the 'Sommet' with newData.
 * */
Sommet& Sommet::operator=(Data newData) {
    data = newData;
    return *this;
}

/** Function : Overloading operator=.
 * Return : 'ArbreB'.
 * Parameter : other, the other tree for the copy.
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
 * Return : Boolean.
 * Parameter : other, the other node for compare.
 * Description : Say if the 'Sommet' is equal to an other.
 * */
bool Sommet::operator==(const Sommet& other) {
    if(data.freq == other.data.freq && data.car == other.data.car) {
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
 * Return : Boolean.
 * Parameter : node, the other node for compare.
 * Description : Say if the 'Sommet' is equal to an other, recursive version.
 * */
bool Sommet::equal(Sommet *node) {
    if(node) {
        if(data.freq != node->data.freq || data.car != node->data.car) {
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
 * Return : Boolean.
 * Parameter : other, the other tree for compare.
 * Description : Say if the 'ArbreB' is equal to an other.
 * */
bool ArbreB::operator==(const ArbreB& other) {
    if(!root && !other.root) { // Two empty trees is always equal
        return true;
    }
    if((!root && other.root) || (root && !other.root)) {
        return false;
    }
    return *root == *other.root; // Use operator== for 'Sommet'
}

/** Function : Overloading operator<<.
 * Return : 'ArbreB'.
 * Parameter : newData, the value to add in the tree.
 * Description : Add a node with the value newData in the tree.
 * */
ArbreB& ArbreB::operator<<(Data newData) {
    if(!root) {
        root = new Sommet(newData);
    }
    else {
        add(root, newData); // Call recursive function
    }
    return *this;
}

/** Function : add.
 * Parameter : node, for recursive call,
 *              newData, the value to add.
 * Description : Add a node with the value newData in the tree, recursive version.
 * */
void ArbreB::add(Sommet *root, Data newData) {
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
 * Parameter : dellData, data need to be deleted.
 * Description : Dell a node with the value dellData in the tree, if
 *              the node with dellData exist.
 * */
ArbreB& ArbreB::operator>>(Data dellData) {
    Sommet *dellNode = find(root, dellData);
    if(!dellNode || !root) { // If haven't root or the value dellData wasen't found
        return *this;
    }
    if(root->data.freq == dellData.freq && root->data.car == dellData.car) {
        if(root->isLeaf()) { // Delete the root
            delete root;
            root = nullptr;
        }
        else { // Swap the root with a random leaf
            Sommet *randLeaf = getRandLeaf(root);
            Data swap = randLeaf->data;
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
 * Parameters : root, node used for recursive call,
 *              dellData, data need to be deleted.
 * Description : Delete a node with the value dellData in the tree, if
 *              the node with dellData exist, recursive version.
 * */
void ArbreB::dell(Sommet *root, Data dellData) {
    if(!root) {
        return;
    }
    if(root->left) {
        if(root->left->data.freq == dellData.freq && root->left->data.car == dellData.car) {
            if(root->left->isLeaf()) { // Delete the left child
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
        if(root->right->data.freq == dellData.freq && root->right->data.car == dellData.car) {
            if(root->right->isLeaf()) { // Delete the right child
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


/** Function : Overloading operator<<.
 * Return : std::ostream.
 * Parameter : flux, where we write, 
 *             node we print.
 * Description : Print the node recursively.
 * */
std::ostream &operator<<(std::ostream &flux, const Sommet& node) {
    flux << "(" << node.data.car << ", " << node.data.freq << "), ";
    if(node.left) {
        flux << *node.left;
    }
    if(node.right) {
        flux << *node.right;
    }
    return flux;
}

/** Function : Overloading operator<<.
 * Return : std::ostream.
 * Parameter : flux, where we write,
 *              tree we print.
 * Description : Print the tree.
 * */
std::ostream &operator<<(std::ostream &flux, const ArbreB& tree) {
    if(tree.root) {
        flux << *tree.root;
    }
    return flux;
}

/** Function : Overloading operator+=.
 * Return : 'ArbreB'.
 * Parameter : other, for merge two trees.
 * Description : Merge two trees.
 * */
ArbreB& ArbreB::operator+=(const ArbreB& other) {
    Sommet *cpyOther = other.root->copy();
    
    Data newRootData;
    newRootData.freq = root->data.freq + cpyOther->data.freq;
    newRootData.car = '\0';
    Sommet *newRoot = new Sommet(newRootData);
    newRoot->left = root;
    newRoot->right = cpyOther;

    root = newRoot;
    return *this;
}

/** Function : Overloading operator-=.
 * Return : 'ArbreB'.
 * Parameter : other, for split two trees.
 * Description : Split two trees.
 * */
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

/** Function : Overloading operator[].
 * Return : 'Sommet*'.
 * Parameter : index, the position of the node in the tree we need to get.
 * Description : Get a precise node in the tree.
 * */
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

/** Function : find.
 * Return : 'Sommet*'.
 * Parameter : root, for recursive call, 
 *             dataSearch, the value we want to find.
 * Description : Split two trees.
 * */
Sommet* ArbreB::find(Sommet* root, Data dataSearch) {
    if(root) {
        if(root->data.freq == dataSearch.freq && root->data.car == dataSearch.car) {
            return root;
        }
        if(root->left) { // If we find at the left.
            Sommet* ret = find(root->left, dataSearch);
            if(ret) {
                return ret; // Don't need to search at the right, return answer.
            }
        }
        if(root->right) {
            return find(root->right, dataSearch);
        }
    }

    return nullptr;
}

/* Getters */
Data Sommet::getData() const {
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
void Sommet::setLeft(Data leftData) {
    if(left) {
        left->data.freq = leftData.freq;
        left->data.car = leftData.car;
    }
    else {
        left = new Sommet(leftData);
    }
}

void Sommet::setRight(Data rightData) {
    if(right) {
        right->data.freq = rightData.freq;
        right->data.car = rightData.car;
    }
    else {
        right = new Sommet(rightData);
    }
}
/* End setters */

/* Methodes */

bool Sommet::equalsData(Data other) {
    return ((data.freq == other.freq)
        && (data.car == other.car));
}

/** Function : Min.
 * Parameter : min, the minimum of the tree.
 * Description : Found the minimum value in the tree, recursive version.
 * */
void Sommet::Min(int *min) {
    if(data.freq <= *min) {
        *min = data.freq;
    }
    if(left) {
        left->Min(min);
    }
    if(right) {
        right->Min(min);
    }
}

/** Function : dataMin
 * Return : int.
 * Description : Found the minimum value in the tree.
 * */
int Sommet::dataMin() {
    int min = INT32_MAX; // Init min with the max value for int
    Min(&min);
    return min;
}

/** Function : Max.
 * Parameter : max, the maximum of the tree.
 * Description : Found the maximum value in the tree, recursive version.
 * */
void Sommet::Max(int *max) {
    if(data.freq >= *max) {
        *max = data.freq;
    }
    if(left) {
        left->Max(max);
    }
    if(right) {
        right->Max(max);
    }
}

/** Function : dataMax
 * Return : int.
 * Description : Found the maximum value in the tree.
 * */
int Sommet::dataMax() {
    int max = INT32_MIN; // Init min with the min value for int
    Max(&max);
    return max;
}

/** Function : isLeaf
 * Return : Boolean.
 * Description : Say if the node is a leaf.
 * */
bool Sommet::isLeaf() {
    return (!left && !right);
}

/** Function : printBeautifulTree
 * Description : Print tree like the next pattern.
 *                  right right child ...
 *      right child
 *                  right left child ...
 * root
 *                  left right child ...
 *      left child
 *                 left left child ...
 * */
void Sommet::printBeautifulTree(int space) {
    if(right) {
        right->printBeautifulTree(space + 1);
    }
    for(int i = 0; i < space; i++) {
        std::cout << "   ";
    }
    std::cout << "(" << data.car << ", " << data.freq << "), " << std::endl;
    if(left) {
        left->printBeautifulTree(space + 1);
    }
}

int maximum(int a, int b){
    return (a > b) ? a : b;
}

/** Function : countDepht.
 * Return : int.
 * Description : Count the depth of the tree.
 * */
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

/** Function : countSize.
 * Return : int.
 * Description : Count the size of the tree.
 * */
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