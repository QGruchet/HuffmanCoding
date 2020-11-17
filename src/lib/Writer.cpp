#include "Writer.hpp"

/* Constructors */
// Default
Writer::Writer() : file("\0") {}

// With param
Writer::Writer(std::string msg) : file(msg) {}
/* End constructors */

/* Methodes */
void Writer::writeBeautifulTreeInFile(Sommet* node, int space) {
  if(std::ifstream(file)){
    remove(file.c_str());
  }

  std::string const nameFile(file);
  std::ofstream flux(nameFile.c_str(), std::ios_base::app);

 
  for(int i = 0; i < space; i++) {
      flux << "|__";
  }
  flux << node->getData() << std::endl;

  if(node->getRight()) {
    writeBeautifulTreeInFile(node->getRight(), space + 1);
  }
   
  if(node->getLeft()) {
    writeBeautifulTreeInFile(node->getLeft(), space + 1);
  }
}

void Writer::writeInFile(std::string msg) {
  if(std::ifstream(file)){
      remove(file.c_str());
  }

  std::string const nameFile(file);
  std::ofstream flux(nameFile.c_str(), std::ios_base::app);

  flux << msg;
}
/* End methodes */
 