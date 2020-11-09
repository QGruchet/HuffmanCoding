#include "Test.hpp"

void Test::allTest() const {
    /* Test Tree.hpp */
    std::cout << "testDefaultBuilderSommet : " << (testDefaultBuilderSommet() ? "succed"  : "failed") << " ! " << std::endl;
    std::cout << "testCopyBuilderSommet : " << (testCopyBuilderSommet() ? "succed"  : "failed") << " ! " << std::endl;
    std::cout << "testDefaultBuilderArbreB : " << (testDefaultBuilderArbreB() ? "succed"  : "failed") << " ! " << std::endl;
    std::cout << "testCopyBuilderArbreB : " << (testCopyBuilderArbreB() ? "succed"  : "failed") << " ! " << std::endl;
    // std::cout << "testBuilderSommetWithParamFailed : " << (testBuilderSommetWithParamFailed() ? "succed"  : "failed") << " ! " << std::endl;
    std::cout << "testBuilderSommetWithParam : " << (testBuilderSommetWithParam() ? "succed"  : "failed") << " ! " << std::endl;
    std::cout << "testBuilderArbreBWithParam : " << (testBuilderArbreBWithParam() ? "succed"  : "failed") << " ! " << std::endl;
    

    /* Test Parser.hpp */
    // std::cout << "testCalculFreqChar : " << ((testCalculFreqChar()) ? "succed" : "failed") << " ! " << std::endl;
}

/* Test Tree.hpp */
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

bool Test::testBuilderSommetWithParamFailed() const {
    Sommet node(-1, '\0');

    return ( (node.getNumCar() == 0)
        && (node.getCar() == '\0')
        && (node.getLeft() == nullptr)
        && (node.getRight() ==  nullptr) );
}

bool Test::testBuilderSommetWithParam() const {
    Sommet node(2, 'e');

    return ( (node.getNumCar() == 2)
        && (node.getCar() == 'e')
        && (node.getLeft() == nullptr)
        && (node.getRight() ==  nullptr) );
}

bool Test::testBuilderArbreBWithParam() const {
    Sommet* node = new Sommet(2, 'e');
    ArbreB tree(node);
    Sommet* root = tree.getRoot();

    return ( (root->getNumCar() == 2)
        && (root->getCar() == 'e')
        && (root->getLeft() == nullptr)
        && (root->getRight() ==  nullptr) );
}
/* End Tree.hpp */

/* Test Parser.hpp */
bool Test::testCalculFreqChar() const {
    std::vector<int> freq = {'h', 1, 'e', 1, 'l', 3, 'o', 2, ' ', 1, 'w', 1, 'r', 1, 'd', 1};

    Parser parser;
    std::vector<int> freq2;
    parser.freqChar("textTest.txt", freq2);

    for(int i = 0; i < 9; ++i) {
        if(freq[i] != freq2[i]) {
            return false;
        }
    }
    return true;
}
/* End Parser.hpp */