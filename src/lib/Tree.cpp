#include "Tree.hpp"

/* Builders */
// Default
Sommet::Sommet() : data(0), left(nullptr), right(nullptr) {}
ArbreB::ArbreB() : depth(0), size(0), root(nullptr)  {}
// End default

ArbreB::ArbreB(Sommet *newRoot) {
  root = newRoot;
  depth = newRoot->getDepth();
  size = 0;
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
    root = add(newData);
  }
  return *this;
}

Sommet* ArbreB::add(int newData) {
  if(rand()%2) {
    if(root->left) {
      root->left = add(newData);
    }
    else {
      root->left = new Sommet(newData);
    }
  }
  else {
    if(root->right) {
      root->right = add(newData);
    }
    else {
      root->right = new Sommet(newData);
    }
  }
  return root;
}

// ArbreB& ArbreB::operator>>(int dellData) {}
// Sommet* ArbreB::dell(int dellData) {}

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
// Sommet* ArbreB::operator[](int) {}
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
// Sommet* ArbreB::find(int dataSearch) {}

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
}
/* End destructors */