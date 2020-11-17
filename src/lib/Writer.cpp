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

  std::ofstream flux(file.c_str(), std::ios_base::app);

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

void Writer::writeResultAllTests() {
  if(std::ifstream(file)) {
    remove(file.c_str());
  }

  std::ofstream flux(file.c_str(), std::ios_base::app);

  Test test;
  std::string OK = " " + test.inGreen("OK") + " ";
  std::string FAIL = test.inRed("FAIL");

  flux << "\n\t> TESTS <" << std::endl;
  flux << "[ " << (test.testDefaultConstructorNode() ? OK : FAIL) << " ] Create a default node.\n";
  flux << "[ " << (test.testCopyConstructorNode() ? OK : FAIL) << " ] Create a node with a copy.\n";
  flux << "[ " << (test.testParamConstructorNode() ? OK : FAIL) << " ] Create a node with a value.\n";
  flux << "[ " << (test.testAssignNode() ? OK : FAIL) << " ] Assign a node in a other .\n";
  flux << "[ " << (test.testEqualsNode() ? OK : FAIL) << " ] Say if two nodes are equals.\n";
  flux << "[ " << (test.testDepth() ? OK : FAIL) << " ] Count the tree's depht.\n";
  flux << "[ " << (test.testSize() ? OK : FAIL) << " ] Count the number of nodes.\n";

  // ArbreB
  flux << "[ " << (test.testDefaultConstructorTree() ? OK : FAIL) << " ] Create a default tree.\n";
  flux << "[ " << (test.testParamConstructorTree() ? OK : FAIL) << " ] Create a tree with the value of the root.\n";
  flux << "[ " << (test.testAssignTree() ? OK : FAIL) << " ] Assign a trees in a other.\n";
  flux << "[ " << (test.TestEqualsTree() ? OK : FAIL) << " ] Say if two tree are equals.\n";
  flux << "[ " << (test.testAdd() ? OK : FAIL) << " ] Add a new node in the tree.\n";
  flux << "[ " << (test.testDell() ? OK : FAIL) << " ] Delete a node in the tree.\n";
  flux << "[ " << (test.testFind() ? OK : FAIL) << " ] Say if a value is in the tree.\n";
  flux << "[ " << (test.testGetNodeAtIndex() ? OK : FAIL) << " ] Get node at index in the tree.\n";
  flux << "[ " << (test.testJoin() ? OK : FAIL) << " ] Join the tree with a other.\n";
  flux << "[ " << (test.testSplit() ? OK : FAIL) << " ] Split the tree in two.\n";

  if(test.getSumTest() == test.getNumTestGlobal()) {
    flux << "> TESTS RESULT : [ \033[0;31m" << test.getSumTest() << "\033[0m/\033[0;32m" << test.getNumTestGlobal() << "\033[0m ] tests passed ! <\n";
  }
  else {
    flux << "> TESTS RESULT : [ \033[0;31m" << test.getSumTest() << "\033[0m/\033[0;32m" << test.getNumTestGlobal() << "\033[0m ] tests passed ! <\n";
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
 