#include "Test.hpp"

void Test::allTest() const {
    /* Test Tree.hpp */
    std::cout << "testDefaultBuilderSommet : " << (testDefaultBuilderSommet() ? "succes"  : "fail") << " ! " << std::endl;
    std::cout << "testCopyBuilderSommet : " << (testCopyBuilderSommet() ? "succes"  : "fail") << " ! " << std::endl;
    std::cout << "testDefaultBuilderArbreB : " << (testDefaultBuilderArbreB() ? "succes"  : "fail") << " ! " << std::endl;
    std::cout << "testCopyBuilderArbreB : " << (testCopyBuilderArbreB() ? "succes"  : "fail") << " ! " << std::endl;
    // std::cout << "testBuilderSommetWithParamFailed : " << (testBuilderSommetWithParamFailed() ? "succes"  : "fail") << " ! " << std::endl;
    std::cout << "testBuilderSommetWithNumCarAndCar : " << (testBuilderSommetWithNumCarAndCar() ? "succes"  : "fail") << " ! " << std::endl;
    std::cout << "testBuilderSommetWithNum : " << (testBuilderSommetWithNum() ? "succes"  : "fail") << " ! " << std::endl;
    std::cout << "testBuilderArbreBWithParam : " << (testBuilderArbreBWithParam() ? "succes"  : "fail") << " ! " << std::endl;
    std::cout << "testCopyArbreB : " << (testCopyArbreB() ? "succes"  : "fail") << " ! " << std::endl;
    std::cout << "testTreeToQueue : " << (testTreeToQueue() ? "succes"  : "fail") << " ! " << std::endl;
    std::cout << "testGetSommetAtIndex : " << (testGetSommetAtIndex() ? "succes"  : "fail") << " ! " << std::endl;
    std::cout << "testAddNode : " << (testAddNode() ? "succes"  : "fail") << " ! " << std::endl;
    std::cout << "testAddNode2 : " << (testAddNode2() ? "succes"  : "fail") << " ! " << std::endl;
    std::cout << "testDepth : " << (testDepth() ? "succes"  : "fail") << " ! " << std::endl;
    std::cout << "testSize : " << (testSize() ? "succes"  : "fail") << " ! " << std::endl;
    std::cout << "testDellNodeAtIndex : " << (testDellNodeAtIndex() ? "succes"  : "fail") << " ! " << std::endl;

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

bool Test::testCopyArbreB() const {
    Sommet *root = new Sommet(1);
    ArbreB tree(root);
    tree.addNode(root, new Sommet(2));
    tree.addNode(root, new Sommet(0));
    tree.addNode(root, new Sommet(3));

    ArbreB treeCopy;
    treeCopy = tree;

    treeCopy.printTree(treeCopy.getRoot(), 0);
    return 0;
}

bool Test::testTreeToQueue() const {
    Sommet *root = new Sommet(1);
    ArbreB tree(root);
    tree.addNode(root, new Sommet(2));
    tree.addNode(root, new Sommet(0));
    tree.addNode(root, new Sommet(3));

    std::queue<Sommet> queueTree;
    tree.toQueue(&queueTree);
    std::queue<Sommet> queueTest;
    queueTest.push(Sommet(1));
    queueTest.push(Sommet(0));
    queueTest.push(Sommet(2));
    queueTest.push(Sommet(3));

    if(queueTest.size() != queueTree.size()) {
        return false;
    }
    bool ret = true;
    while(!queueTree.empty()) {
        ret &= (queueTree.front().getNumCar() == queueTest.front().getNumCar());
        queueTest.pop();
        queueTree.pop();
    }
    return ret;
}

bool Test::testGetSommetAtIndex() const {
    Sommet *root = new Sommet(1);
    ArbreB tree(root);
    tree.addNode(root, new Sommet(2));
    tree.addNode(root, new Sommet(0));
    tree.addNode(root, new Sommet(3));

    return tree[4]->getNumCar() == 3;
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
    
    return 1;
}

bool Test::testAddNode2() const {
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
    
    return 1;
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
    tree < Sommet(2);
    tree < Sommet(0);
    tree < Sommet(3);

    return ((tree[4]->getNumCar() == 3) && (tree.getSize() == 4) && (tree.getDepth(root) == 2));
}

bool Test::testDellNodeAtIndex() const {
    Sommet *root = new Sommet(1);
    ArbreB tree(root);
    tree < Sommet(2);
    tree < Sommet(0);
    tree < Sommet(3);
    tree > 3;

    tree.printTree(root, 0);

    return ((tree[3]->getNumCar() == 3) && (tree.getSize() == 3) && (tree.getDepth(root) == 1));
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