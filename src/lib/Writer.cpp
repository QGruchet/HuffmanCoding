/**
 * Writer.cpp : You can found here all functions implemented for the Writer class.
 * Author : Mickael.
 **/

#include "Writer.hpp"

/**
 * Function : Default constructor.
 * Return : Writer.
 * Description : Default constructor.
 * */
Writer::Writer() : file("\0") {}

/**
 * Function : Constructor with parameter.
 * Return : Writer.
 * Parameter : nameFile : the name of the file.
 * Description : Constructor with parameter.
 * */
Writer::Writer(std::string nameFile) : file(nameFile) {}

/**
 * Function : writeBeautifulTreeInFile.
 * Parameter : Tree, the tree need to write in a file.
 * Description : Write a tree in a file.
 * */
void Writer::writeBeautifulTreeInFile(ArbreB tree) {
    // Setup flux and open file
    std::ofstream flux;
    flux.open(file.c_str(), std::ios::trunc);

    // If the file is open
    if(flux) {
        // Write some informations
        Sommet *root = tree.getRoot();
        flux << root->countSize() << "\n";
        flux << root->getData() << "\n";
        flux << root->countDepth() << "\n";
        flux << root->dataMin() << "\n";
        flux << root->dataMax() << "\n";

        // Write the tree
        writeBeautifulTreeInFileRec(root, 0, flux);
    }
    else {
        std::cout << "ERROR : can't open file" << std::endl;
    }
}

/**
 * Function : writeBeautifulTreeInFileRec.
 * Parameter : node, the node need to write in a file, recursive version.
 *                 flux, where we write.
 * Description : Write a tree in a file.
 * */
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

/**
 * Function : writeResultAllTests.
 * Description : Write result of tests.
 * */
void Writer::writeResultAllTests() {
  // Setup flux and open file
  std::ofstream flux(file.c_str(), std::ios::out | std::ios::trunc);

  // If the file is open
  if(flux) {
    bool withColor = false;
    Test test(withColor);
    // Sommet
    flux<< "\t> TESTS <\n";
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
 