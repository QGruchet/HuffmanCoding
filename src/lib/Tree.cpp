#include "Tree.hpp"

/* Constructors */
// Default
Sommet::Sommet() : data(0), left(nullptr), right(nullptr) {}
ArbreB::ArbreB() : root(nullptr)  {}
// End default

// Copy
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
// End copy

ArbreB::ArbreB(int rootData) {
  root = new Sommet(rootData);
}

Sommet::Sommet(int newData) : data(newData), left(nullptr), right(nullptr) {}
/* End Constructors */

/* Overloaded */
// Operator=
Sommet& Sommet::operator=(Sommet other) {
  if(this != &other) {
    data = other.data;
    left = other.left->copy();
    right = other.right->copy();
  }

  return *this;
}

ArbreB& ArbreB::operator=(const ArbreB& other) {
  if(this != &other) {
    if(!root) {
      root = new Sommet(other.root->data);
    }

    *root = *other.root;
  }
  
  return *this;
}
// End operator=



// Operator<<
ArbreB& ArbreB::operator<<(int newData) {
  if(!root) {
    root = new Sommet(newData);
  }
  else {
    add(root, newData);
  }
  return *this;
}

void ArbreB::add(Sommet *root, int newData) {
  if(rand()%2) {
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

ArbreB& ArbreB::operator>>(int dellData) {
  Sommet *dellNode = find(root, dellData); // Find the first node where is dellData
  if(!dellNode || !root) {
    return *this;
  }
  if(root->data == dellData) { // Dell the root
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
      else{
        Sommet *randLeaf = getRandLeaf(root->left);
        int swap = randLeaf->data;
        randLeaf->data = root->left->data;
        root->left->data = swap;

        dell(root->left, dellData);
      }
    }
    else {
      dell(root->left, dellData);
    }
  }
  if(root->right) {
    if(root->right->data == dellData) {
      if(root->right->isLeaf()) {
        delete root->right;
        root->right = nullptr;
        return;
      }
      else{
        Sommet *randLeaf = getRandLeaf(root->right);
        int swap = randLeaf->data;
        randLeaf->data = root->right->data;
        root->right->data = swap;

        dell(root->right, dellData);
      }
    }
    else {
      dell(root->right, dellData);
    }
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
ArbreB& ArbreB::operator+=(const ArbreB& other) { // Join two tree with a new root
  Sommet *cpyOther = other.root->copy();

  Sommet *newRoot = new Sommet(root->data + cpyOther->data);
  newRoot->left = root;
  newRoot->right = cpyOther;

  root = newRoot;

  return *this;
}

ArbreB& ArbreB::operator-=(ArbreB& other) {
  if(!other.root && root && root->left && root->right) {
    other.root = root->right->copy();
    root = root->left;
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

/* Methodes */
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

void Sommet::printBeautifulTreeInFile(int space) {
  
  if(std::ifstream("src/out/binary.txt")){
    remove("src/out/binary.txt");
    // std::cout << "Suppression de binary_tree.dot" << std::endl;
  }
  //On creer le fichier
  std::string const nomFichier("binary.txt");
  std::ofstream flux(nomFichier.c_str(), std::ios_base::app);


  if(right) {
    right->printBeautifulTreeInFile(space + 1);
  }
  for(int i = 0; i < space; i++) {
    std::cout << "   ";
    flux << "   ";
  }
  flux << this->data << std::endl;
  if(left) {
    left->printBeautifulTreeInFile(space + 1);
  }
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