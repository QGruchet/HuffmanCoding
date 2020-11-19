#include "Writer.hpp"

/* Constructors */
// Default
Writer::Writer() : file("\0") {}

// With param
Writer::Writer(std::string msg) : file(msg) {}
/* End constructors */

/* Methodes */
void Writer::writeBeautifulTreeInFile(ArbreB tree) {
    // Setup flux and open file
    std::ofstream flux;
    flux.open(file.c_str(), std::ios::trunc);

    // If the file is open
    if(flux) {
        Sommet *root = tree.getRoot();
        flux << root->countSize() << "\n";
        flux << root->getData() << "\n";
        flux << root->countDepth() << "\n";
        flux << root->dataMin() << "\n";
        flux << root->dataMax() << "\n";
        writeBeautifulTreeInFileRec(root, 0, flux);
    }
    else {
        std::cout << "ERROR : can't open file" << std::endl;
    }
}

void Writer::writeBeautifulTreeInFileRec(Sommet* node, int space, std::ofstream& flux) {
    for(int i = 0; i < space; i++) {
        flux << "|__";
    }
    flux << node->getData() << std::endl;
    if(node->getRight()) {
        writeBeautifulTreeInFileRec(node->getRight(), space + 1, flux);
    }
    if(node->getLeft()) {
        writeBeautifulTreeInFileRec(node->getLeft(), space + 1, flux);
    }
    if(space == 0) {
        flux.close();
    }
}

void Writer::writeResultAllTests() {
  // Setup flux and open file
  std::ofstream flux(file.c_str(), std::ios::out | std::ios::trunc);

  // If the file is open
  if(flux) {
    Test test;
    // Sommet
    flux<< "\n\t> TESTS <\n";
    flux << test.testDefaultConstructorNode();
    flux << test.testCopyConstructorNode();
    flux << test.testParamConstructorNode();
    flux << test.testEqualsNode();
    flux << test.testAssignNode();
    flux << test.testDepth();
    flux << test.testSize();

    // ArbreB
    flux << test.testDefaultConstructorTree();
    flux << test.testParamConstructorTree();
    flux << test.testAssignTree();
    flux << test.TestEqualsTree();
    flux << test.testAdd();
    flux << test.testDell();
    flux << test.testFind();
    flux << test.testGetNodeAtIndex();
    flux << test.testJoin();
    flux << test.testSplit();

    if(test.getSumTest() == test.getNumTestGlobal()) {
        flux << "> TESTS RESULT : [ " << test.getSumTest() << "/" << test.getNumTestGlobal() << " ] tests passed ! <\n";
    }
    else {
        flux << "> TESTS RESULT : [ " << test.getSumTest() << "/" << test.getNumTestGlobal() << " ] tests passed ! <\n";
    }

    flux.close();
  }
  else {
    std::cout << "ERROR : can't open file" << std::endl;
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
 