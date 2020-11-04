#include "Test.hpp"

void Test::allTest() const {
    std::cout << "testDefaultBuilderSommet : " << (testDefaultBuilderSommet() ? "succed"  : "failed") << " ! " << std::endl;
    std::cout << "testCopyBuilderSommet : " << (testCopyBuilderSommet() ? "succed"  : "failed") << " ! " << std::endl;
    std::cout << "testDefaultBuilderArbreB : " << (testDefaultBuilderArbreB() ? "succed"  : "failed") << " ! " << std::endl;
    std::cout << "testCopyBuilderArbreB : " << (testCopyBuilderArbreB() ? "succed"  : "failed") << " ! " << std::endl;
}

bool Test::testDefaultBuilderSommet() const {
    Sommet node;

    return ( (node.getNumCar() == 0)
        && (node.getCar() == '\0')
        && (node.getLeft() == nullptr)
        && (node.getRight() ==  nullptr) );
}

bool Test::testDefaultBuilderArbreB() const {
    ArbreB tree;

    return ( tree.getRoot() == nullptr );
}

bool Test::testCopyBuilderSommet() const {
    Sommet node;
    Sommet nodeCopy(node);

    return ( (node.getNumCar() == nodeCopy.getNumCar())
        && (node.getCar() == nodeCopy.getCar())
        && (node.getLeft() == nodeCopy.getLeft())
        && (node.getRight() ==  nodeCopy.getRight()) );
}

bool Test::testCopyBuilderArbreB() const {
    ArbreB tree;
    ArbreB treeCopy;

    return ( tree.getRoot() == treeCopy.getRoot() );
}