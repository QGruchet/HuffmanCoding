#include "Writer.hpp"

void Writer::writeInFile(std::string msg) {
  if(std::ifstream(file)){
      remove(file.c_str());
  }

  std::string const nameFile(file);
  std::ofstream flux(nameFile.c_str(), std::ios_base::app);

  flux << msg;
}

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
    node->getRight()->writeBeautifulTreeInFile(space + 1);
  }
   
  if(node->getLeft()) {
    node->getLeft()->writeBeautifulTreeInFile(space + 1);
  }
}
 