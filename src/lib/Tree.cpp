#include "Tree.hpp"

/* Builders */
// Default
Sommet::Sommet() : data(0), left(nullptr), right(nullptr) {}
ArbreB::ArbreB() : size(0), root(nullptr)  {}
// End default

// Copy
Sommet::Sommet(const Sommet& other) {}
ArbreB::ArbreB(const ArbreB& other) {}
// End copy

ArbreB::ArbreB(int rootData) {
  size = 0;
  root = new Sommet(rootData);
}

Sommet::Sommet(int newData) : data(newData), left(nullptr), right(nullptr) {}
/* End builders */

/* Overloaded */
// Operator=
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

ArbreB& ArbreB::operator>>(int dellData) {}

void ArbreB::dell(Sommet *root, int dellData) {}

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
// End operator+=, operator-=

// Operator[]
Sommet* ArbreB::operator[](int) {}
Sommet* ArbreB::find(int dataSearch) {}
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
/* End printers */

/* Destructors */
Sommet::~Sommet() {
  if(left) {
    delete this;
  }
  if(right) {
    delete this;
  }
}
ArbreB::~ArbreB() {
  if(root) {
    delete root;
  }
  root = nullptr;
}
/* End destructors */