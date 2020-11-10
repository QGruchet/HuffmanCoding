#include "Test.hpp"

void Test::allTest() const {
    /* Test Tree.hpp */
    std::cout << "testDefaultBuilderSommet : " << (testDefaultBuilderSommet() ? "succed"  : "failed") << " ! " << std::endl;
    std::cout << "testCopyBuilderSommet : " << (testCopyBuilderSommet() ? "succed"  : "failed") << " ! " << std::endl;
    std::cout << "testDefaultBuilderArbreB : " << (testDefaultBuilderArbreB() ? "succed"  : "failed") << " ! " << std::endl;
    std::cout << "testCopyBuilderArbreB : " << (testCopyBuilderArbreB() ? "succed"  : "failed") << " ! " << std::endl;
    // std::cout << "testBuilderSommetWithParamFailed : " << (testBuilderSommetWithParamFailed() ? "succed"  : "failed") << " ! " << std::endl;
    std::cout << "testBuilderSommetWithNumCarAndCar : " << (testBuilderSommetWithNumCarAndCar() ? "succed"  : "failed") << " ! " << std::endl;
    std::cout << "testBuilderSommetWithNum : " << (testBuilderSommetWithNum() ? "succed"  : "failed") << " ! " << std::endl;
    std::cout << "testBuilderArbreBWithParam : " << (testBuilderArbreBWithParam() ? "succed"  : "failed") << " ! " << std::endl;
    std::cout << "testAddNode : " << (testAddNode() ? "succed"  : "failed") << " ! " << std::endl;
    std::cout << "testDepth : " << (testDepth() ? "succed"  : "failed") << " ! " << std::endl;
    std::cout << "testSize : " << (testSize() ? "succed"  : "failed") << " ! " << std::endl;
    std::cout << "testTreeToVector : " << (testTreeToVector() ? "succed"  : "failed") << " ! " << std::endl;

    /* Test Parser.hpp */
    // std::cout << "testCalculFreqChar : " << ((testCalculFreqChar()) ? "s ucced" : "failed") << " ! " << std::endl;
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

    return ( (node.getNumCar() == -1)
        && (node.getCar() == '\0')
        && (node.getLeft() == nullptr)
        && (node.getRight() ==  nullptr) );
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

bool Test::testAddNode() const {
    Sommet* root = new Sommet(2);
    ArbreB tree(root);

    tree.addNode(root, new Sommet(3));
    tree.addNode(root, new Sommet(1));
    tree.addNode(root, new Sommet(13));
    tree.addNode(root, new Sommet(6));
    tree.addNode(root, new Sommet(0));
    tree.addNode(root, new Sommet(3));
    tree.addNode(root, new Sommet(5));
    tree.addNode(root, new Sommet(69));
    
    return 0;
}

bool Test::testDepth() const {
    Sommet *root = new Sommet(1);
    ArbreB tree(root);
    tree.addNode(root, new Sommet(2));
    tree.addNode(root, new Sommet(0));
    tree.addNode(root, new Sommet(3));

    return (tree.getDepth(root) == 2);
}

bool Test::testSize() const {
    Sommet *root = new Sommet(1);
    ArbreB tree(root);
    tree.addNode(root, new Sommet(2));
    tree.addNode(root, new Sommet(0));
    tree.addNode(root, new Sommet(3));

    return (tree.getSize() == 4);
}

bool Test::testTreeToVector() const {
    Sommet *root = new Sommet(1);
    ArbreB tree(root);
    tree.addNode(root, new Sommet(2));
    tree.addNode(root, new Sommet(0));
    tree.addNode(root, new Sommet(3));

    std::vector<Sommet*> vectorTree;
    tree.toVector(vectorTree);
    std::vector<Sommet*> vectorTest = {new Sommet(1), new Sommet(0), new Sommet(2), new Sommet(3)};

    return vectorTree == vectorTest;
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