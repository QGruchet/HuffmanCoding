#include "Writer.hpp"

Writer::Writer(){
  file = '\0';
}

Writer::Writer(std::string msg){
  file = msg;
}

void Writer::writeInFile(std::string msg) {
  if(std::ifstream(file)){
      remove(file.c_str());
  }

  std::string const nameFile(file);
  std::ofstream flux(nameFile.c_str(), std::ios_base::app);

  flux << msg;
}

void Writer::writeBeautifulTreeInFile(Sommet* node, int space) {
  Writer w;
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
    w.writeBeautifulTreeInFile(node->getRight(), space + 1);
  }
   
  if(node->getLeft()) {
    w.writeBeautifulTreeInFile(node->getLeft(), space + 1);
  }
}
 