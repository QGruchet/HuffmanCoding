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
Sommet& Sommet::operator<<(int newData) { // Add randomly newData in the tree
  if(rand()%2) { // Look at left if rand is even
    if (left) { // Empty child, create new node
      *left << newData;
    }
    else { // Go on left
      left = new Sommet(newData);
    }
  }
  else { // Look at right is not even
    if (right) { // Empty child, create new node
      *right << newData;
    }
    else { // Go on right
      right = new Sommet(newData);
    }
  }
  return *this;
}

Sommet& Sommet::operator>>(int dellData) {
  if(numCar == dellData) { // Dell the root
    Sommet *tmp = nullptr;
    if(left) {
      numCar = left->numCar;
      tmp = left;
      left = nullptr;
    }
    else if(right) {
      numCar = right->numCar;
      tmp = right;
      right = nullptr;
    }
    if(tmp) {
      delete tmp;
    }
    return *this;
  }

  if(left) {
    if(left->numCar == dellData) {
      Sommet *dellNode = left;
      if(left->left) { // if we have left child we relace dellNode by is left child
        left = left->left;
      }
      else if(left->right) { // if haven't left child we replace by is right child
        left = left->right;
      }
      else { // If we haven't any child
        left = nullptr;
      }
      delete dellNode;
      return *this;
    }
    else {
      *left >> dellData;
    }
  }
  else if(right) {
    if(right->numCar == dellData) {
      Sommet *dellNode = right;
      if(right->left) { // Relace dellNode by is left child if existe
        right = right->left;
      }
      else if(left->right) { // Else by is right child
        right = right->right;
      }
      else { // If we haven't any child
        right = nullptr;
      }
      delete dellNode;
      return *this;
    }
    else {
      *right >> dellData;
    }
  }

  return *this;
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
void Sommet::Min(int *min) {
  if(numCar <= *min) {
    *min = numCar;
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
  if(numCar >= *max) {
    *max = numCar;
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

bool Sommet::found(int dataSearch) {
  bool found = false;
  foundRec(&found, dataSearch);
  return found;
}

void Sommet::foundRec(bool *found, int dataSearch) {
  if(numCar == dataSearch) {
    *found = true;
  }
  if(left) {
    left->foundRec(found, dataSearch);
  }
  if(right) {
    right->foundRec(found, dataSearch);
  }
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
    // std::cout << "Suppression de binary_tree.dot" << std::endl;
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