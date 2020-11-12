#include "Test.hpp"

void Test::allTest() const {
    /* Test Tree.hpp */
    std::cout << "testDefaultBuilderSommet : " << (testDefaultBuilderSommet() ? "succes"  : "fail") << " ! " << std::endl;
    std::cout << "testCopyBuilderSommet : " << (testCopyBuilderSommet() ? "succes"  : "fail") << " ! " << std::endl;
    std::cout << "testDefaultBuilderArbreB : " << (testDefaultBuilderArbreB() ? "succes"  : "fail") << " ! " << std::endl;
    std::cout << "testCopyBuilderArbreB : " << (testCopyBuilderArbreB() ? "succes"  : "fail") << " ! " << std::endl;
    std::cout << "testBuilderSommetWithNumCarAndCar : " << (testBuilderSommetWithNumCarAndCar() ? "succes"  : "fail") << " ! " << std::endl;
    std::cout << "testBuilderSommetWithNum : " << (testBuilderSommetWithNum() ? "succes"  : "fail") << " ! " << std::endl;
    std::cout << "testBuilderArbreBWithParam : " << (testBuilderArbreBWithParam() ? "succes"  : "fail") << " ! " << std::endl;
    std::cout << "testCopyArbreB : " << (testCopyArbreB() ? "succes"  : "fail") << " ! " << std::endl;
    std::cout << "testTreeToQueue : " << (testTreeToQueue() ? "succes"  : "fail") << " ! " << std::endl;
    std::cout << "testGetSommetAtIndex : " << (testGetSommetAtIndex() ? "succes"  : "fail") << " ! " << std::endl;
    std::cout << "testadd : " << (testAdd() ? "succes"  : "fail") << " ! " << std::endl;
    std::cout << "testadd2 : " << (testAdd2() ? "succes"  : "fail") << " ! " << std::endl;
    std::cout << "testDepth : " << (testDepth() ? "succes"  : "fail") << " ! " << std::endl;
    std::cout << "testSize : " << (testSize() ? "succes"  : "fail") << " ! " << std::endl;
    std::cout << "testDellNodeAtIndex : " << (testDellNodeAtIndex() ? "succes"  : "fail") << " ! " << std::endl;
    createDot();
    /* Test Parser.hpp */
    // std::cout << "testCalculFreqChar : " << ((testCalculFreqChar()) ? "s ucced" : "fail") << " ! " << std::endl;
}

/* Test Tree.hpp */
bool Test::testDefaultBuilderSommet() const {
    Sommet node;

    return ( (node.getNumCar() == -1)
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
        && (nodeCopy.getLeft() == nullptr)
        && (nodeCopy.getRight() ==  nullptr) );
}

bool Test::testCopyBuilderArbreB() const {
    ArbreB tree;
    ArbreB treeCopy;

    return ( tree.getRoot() == treeCopy.getRoot() );
}

bool Test::testBuilderSommetWithNumCarAndCar() const {
    Sommet node(2, 'e');

    return ( (node.getNumCar() == 2)
        && (node.getCar() == 'e')
        && (node.getLeft() == nullptr)
        && (node.getRight() ==  nullptr) );
}

bool Test::testBuilderSommetWithNum() const {
    Sommet node(2);

    return ( (node.getNumCar() == 2)
        && (node.getCar() == '\0')
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

bool Test::testCopyArbreB() const {
    Sommet *root = new Sommet(1);
    ArbreB tree(root);
    root->add(root, 2);
    root->add(root, 0);
    root->add(root, 3);
    
    return 0;
}

bool Test::testTreeToQueue() const {
    Sommet *root = new Sommet(1);
    ArbreB tree(root);
    root->add(root, 2);
    root->add(root, 0);
    root->add(root, 3);

    return 0;
}

bool Test::testGetSommetAtIndex() const {
    Sommet *root = new Sommet(1);
    ArbreB tree(root);
    root->add(root, 2);
    root->add(root, 0);
    root->add(root, 3);

    return 0;
}

bool Test::testAdd() const {
    Sommet* root = new Sommet(2);
    ArbreB tree(root);

    root->add(root, 3);
    root->add(root, 1);
    root->add(root, 13);
    root->add(root, 6);
    root->add(root, 0);
    root->add(root, 3);
    root->add(root, 5);
    root->add(root, 69);
    
    return 1;
}

bool Test::testAdd2() const {
    return 0;
}

bool Test::testDepth() const {
    Sommet *root = new Sommet(1);
    ArbreB tree(root);
    root->add(root, 2);
    root->add(root, 0);
    root->add(root, 3);

    return (tree.getDepth(root) == 2);
}

bool Test::testSize() const {
    return 0;
}

bool Test::testDellNodeAtIndex() const {
    return 0;
}

void Test::createDot() const {
    Sommet *root = new Sommet(2);
    root->add(root, 5);
    root->add(root, 1);
    root->add(root, 7);
    root->add(root, 6);
    root->add(root, 4);
    root->add(root, 0);
    root->ecritureHeader();
    root->ecritureFichier(root);
    root->ecritureEnder();
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