/**
 * Test.cpp : You can found here all functions implemented for the Test class.
 * Author : Mickael.
 **/
#include "Test.hpp"
#include <string>

/**
 * Function : Constructor by default.
 * Return : 'Test'.
 * Description : Create an object 'Test' with default parameters.
 * */
Test::Test() : sumTest(0), numTestGlobal(0), inColor(true) {}

/**
 * Function : Constructor with parameters.
 * Return : 'Test'.
 * Description : Create an object 'Test' with default parameters and color.
 * */
Test::Test(bool withColor) : sumTest(0), numTestGlobal(0), inColor(withColor) {}

/**
 * Function : inRed.
 * Arguments : std::string msg.
 * Return : std::string.
 * Description : Colorized the string 'msg' in red.
 * */
std::string inRed(std::string msg) {
    return "\033[0;31m" + msg + "\033[0m";
}

/**
 * Function : inGreen.
 * Arguments : std::string msg.
 * Return : std::string.
 * Description : Colorized the string 'msg' in green.
 * */
std::string inGreen(std::string msg) {
    return "\033[0;32m" + msg + "\033[0m";
} 

/* Global variables */
std::string OK = " " + inGreen("OK") + " ";
std::string FAIL = inRed("FAIL");

/**
 * Function : allTest.
 * Description : Print all results of test in our terminal.
 * */
void Test::allTest() {
    /* Test Tree */
    // Sommet
    std::cout << "\n\t> TESTS <" << std::endl;
    std::cout << testDefaultConstructorNode() << std::endl;
    std::cout << testCopyConstructorNode() << std::endl;
    std::cout << testParamConstructorNode() << std::endl;
    std::cout << testEqualsNode() << std::endl;
    std::cout << testAssignNode() << std::endl;
    std::cout << testDepth() << std::endl;
    std::cout << testSize() << std::endl;

    // ArbreB
    std::cout << testDefaultConstructorTree() << std::endl;
    std::cout << testParamConstructorTree() << std::endl;
    std::cout << testAssignTree() << std::endl;
    std::cout << TestEqualsTree() << std::endl;
    std::cout << testAdd() << std::endl;
    std::cout << testDell() << std::endl;
    std::cout << testFind() << std::endl;
    std::cout << testGetNodeAtIndex() << std::endl;
    std::cout << testJoin() << std::endl;
    std::cout << testSplit() << std::endl;

    /* Test Parser */
    // std::cout << "testCalculFreqChar : " << ((testCalculFreqChar()) ? "s ucced" : "fail") << " ! " << std::endl;
    
    if(inColor) {
        if(sumTest == numTestGlobal) {
            std::cout << "> TESTS RESULT : [ \033[0;31m" << sumTest << "\033[0m/\033[0;32m" << numTestGlobal << "\033[0m ] tests passed ! <\n" << std::endl;
        }
        else {
            std::cout << "> TESTS RESULT : [ \033[0;31m" << sumTest << "\033[0m/\033[0;32m" << numTestGlobal << "\033[0m ] tests passed ! <\n" << std::endl;
        }
    }
    else {
        std::cout << "> TESTS RESULT : [ " << sumTest << "/" << numTestGlobal << " ] tests passed ! <\n" << std::endl;
    }
    
}

/**
 * Function : testDefaultConstructorNode.
 * Return : std::string.
 * Description : Test if constructor by defautl is a success. Return 'OK' if yes, 'FAIL' if no.
 * */
std::string Test::testDefaultConstructorNode() {
    Sommet node;
    bool ret = ( (node.getData() == 0)
                && (node.getLeft() == nullptr)
                && (node.getRight() == nullptr)
                );

    sumTest += int(ret);
    numTestGlobal += 1;
    if(inColor) {
        return "[ " + (ret ? OK : FAIL) + " ] Create a default node.";
    }
    std::string tmp = (ret ? " OK " : "FAIL");
    return "[ " + tmp + " ] Create a default node.\n";
}

/**
 * Function : testCopyConstructorNode.
 * Return : std::string.
 * Description : Check if constructor by copy is a success.
 * */
std::string Test::testCopyConstructorNode() { 
    Sommet node(1);
    Sommet node2(node);
    bool ret = ( (node2.getData() == node.getData())
                && (node2.getLeft() == node.getLeft())
                && (node2.getRight() == node.getRight())
                );

    sumTest += int(ret);
    numTestGlobal += 1;
    if(inColor) {
        return "[ " + (ret ? OK : FAIL) + " ] Create a node with a copy.";
    }
    std::string tmp = (ret ? " OK " : "FAIL");
    return "[ " + tmp + " ] Create a node with a copy.\n";
}

/**
 * Function : testParamConstructorNode.
 * Return : std::string.
 * Description : Check if constructor by default without child is a success.
 * */
std::string Test::testParamConstructorNode() {
    Sommet node(1);
    bool ret = ( (node.getData() == 1)
                && (node.getLeft() == nullptr)
                && (node.getRight() == nullptr)
                );

    sumTest += int(ret);
    numTestGlobal += 1;
    if(inColor) {
        return "[ " + (ret ? OK : FAIL) + " ] Create a node with a value.";
    }
    std::string tmp = (ret ? " OK " : "FAIL");
    return "[ " + tmp + " ] Create a node with a value.\n";
}

/**
 * Function : testAssignNode.
 * Return : std::string.
 * Description : Check if operator= is a success.
 * */
std::string Test::testAssignNode() {
    ArbreB tree2(2);
    tree2 << 4;
    tree2 << 6;
    tree2 << 8;
    tree2 << 10;
    Sommet cpyTree2 = *tree2.getRoot();
    bool ret = (cpyTree2 == *tree2.getRoot());

    sumTest += int(ret);
    numTestGlobal +=1;
    if(inColor) {
        return "[ " + (ret ? OK : FAIL) + " ] Assign a node in a other .";
    }
    std::string tmp = (ret ? " OK " : "FAIL");
    return "[ " + tmp + " ] Assign a node in a other .\n";
}

/**
 * Function : testEqualsNode.
 * Return : std::string.
 * Description : Check if two node are equals is a success.
 * */
std::string Test::testEqualsNode() {
    std::string retStr, retStr2, tmp;

    // Test with two empty nodes
    Sommet emptyNode;
    Sommet emptyNode2;
    bool ret1 = (emptyNode == emptyNode2);
    if(inColor) { 
        retStr = "\t[ " + (ret1 ? OK : FAIL) + " ] Two empty nodes equals.\n";
    }
    else {
        tmp = (ret1 ? " OK " : "FAIL");
        retStr2 = "\t[ " + tmp + " ] Two empty nodes equals.\n";
    }

    // Test one empty and one full
    Sommet node(1);
    node.setLeft(2); // Set manually all nodes because operator<< add randomly, more hard to check if their equals
    node.setRight(3);
    node.getLeft()->setLeft(4);
    node.getLeft()->setRight(5);
    node.getRight()->setLeft(6);
    node.getRight()->setRight(7);
    bool ret2 = ((emptyNode == node) == false);
    if(inColor) {
        retStr += "\t[ " + (ret2 ? OK : FAIL) + " ] One empty and one full.\n";
    }
    else {
        tmp = (ret2 ? " OK " : "FAIL");
        retStr2 += "\t[ " + tmp + " ] One empty and one full.\n";
    }

    // Test two full nodes equals
    Sommet node2(1);
    node2.setLeft(2);
    node2.setRight(3);
    node2.getLeft()->setLeft(4);
    node2.getLeft()->setRight(5);
    node2.getRight()->setLeft(6);
    node2.getRight()->setRight(7);
    bool ret3 = (node == node2);
    if(inColor) {
        retStr += "\t[ " + (ret3 ? OK : FAIL) + " ] Two full nodes equals.\n";
    }
    else {
        tmp = (ret3 ? " OK " : "FAIL");
        retStr2 += "\t[ " + tmp + " ] Two full nodes equals.\n";
    }

    // Test two full nodes not equal
    Sommet nodes3(1);
    node2.setLeft(2);
    node2.setRight(3);
    node2.getLeft()->setLeft(4);
    node2.getLeft()->setRight(10);
    node2.getRight()->setLeft(6);
    node2.getRight()->setRight(7);
    bool ret4 = ((node == node2) == false);
    if(inColor) {
        retStr += "\t[ " + (ret4 ? OK : FAIL) + " ] Two full nodes not equal.\n";
    }
    else {
        tmp = (ret4 ? " OK " : "FAIL");
        retStr2 += "\t[ " + tmp + " ] Two full nodes not equal.\n";
    }

    // Return all sub tests
    bool ret = ret1 & ret2 & ret3 & ret4;
    sumTest += int(ret);
    numTestGlobal +=1;
    if(inColor) {
        return retStr + "[ " + (ret? OK : FAIL) + " ] Say if two nodes are equals.";
    }
    else {
        tmp = (ret ? " OK " : "FAIL");
        return retStr2 + "[ " + tmp + " ] Say if two nodes are equals.\n";
    }
}

/**
 * Function : testDepth.
 * Return : 'std::string'.
 * Description : Check the depth of the tree. If the tree has no child, depth = 1. If he has child, depth  = 2. If child has child, depth = 3.....
 * */
std::string Test::testDepth() {
    std::string retStr, retStr2, tmp;

    // Test with only root
    ArbreB tree(1);
    bool ret1 = (tree.getRoot()->countDepth() == 1);
    if(inColor) {
        retStr = "\t[ " + (ret1 ? OK : FAIL) + " ] Root tree depth.\n";
    }
    else {
        tmp = (ret1 ? " OK " : "FAIL");
        retStr2 = "\t[ " + tmp + " ] Root tree depth.\n";
    }

    // Test with full tree
    ArbreB tree2(1);
    tree2.getRoot()->setLeft(2);
    tree2.getRoot()->setRight(3);
    tree2.getRoot()->getLeft()->setLeft(4);
    bool ret2 = (tree2.getRoot()->countDepth() == 3);
    if(inColor) {
        retStr += "\t[ " + (ret2 ? OK : FAIL) + " ] Full tree depth.\n";
    }
    else {
        tmp = (ret2 ? " OK " : "FAIL");
        retStr2 += "\t[ " + tmp + " ] Full tree depth.\n";
    }

    // Return all sub tests
    bool ret = ret1 & ret2;
    sumTest += int(ret);
    numTestGlobal += 1;
    if(inColor) {
        return retStr + "[ " + (ret ? OK : FAIL) + " ] Count the tree's depht.";
    }
    else {
        tmp = (ret ? " OK " : "FAIL");
        return retStr2 + "[ " + tmp + " ] Count the tree's depht.\n";
    }
}

/**
 * Function : testSize.
 * Return : std::string.
 * Description : Check the size of tree. One node => size = 1, two nodes => size = 2...
 * */
std::string Test::testSize() {
    std::string retStr, retStr2, tmp;

    // Test size with only root
    ArbreB tree(1);
    bool ret1 = (tree.getRoot()->countSize() == 1);
    if(inColor) {
        retStr = "\t[ " + (ret1 ? OK : FAIL) + " ] Root tree size.\n";
    }
    else {
        tmp = (ret1 ? " OK " : "FAIL");
        retStr2 = "\t[ " + tmp + " ] Root tree size.\n";
    }

    // Test size with full tree
    ArbreB tree2(1);
    tree2 << 2;
    tree2 << 3;
    tree2 << 4;
    bool ret2 = (tree2.getRoot()->countSize() == 4);
    if(inColor) {
        retStr += "\t[ " + (ret2 ? OK : FAIL) + " ] Full tree size.\n";
    }
    else {
        tmp = (ret2 ? " OK " : "FAIL");
        retStr2 += "\t[ " + tmp + " ] Full tree size.\n";
    }

    // Return all sub tests
    bool ret = ret1 & ret2;
    sumTest += int(ret);
    numTestGlobal += 1;
    if(inColor) {
        return retStr + "[ " + (ret ? OK : FAIL) + " ] Count the number of nodes.";
    }
    else {
        tmp = (ret ? " OK " : "FAIL");
        return retStr2 + "[ " + tmp + " ] Count the number of nodes.\n";
    }
}

// ArbreB
/**
 * Function : testCopyConstructorNode.
 * Return : std::string.
 * Description : Check if constructor by default is a success.
 * */
std::string Test::testDefaultConstructorTree() {
    ArbreB tree;
    bool ret = (tree.getRoot() == nullptr);

    sumTest += int(ret);
    numTestGlobal += 1;
    if(inColor) {
        return "[ " + (ret ? OK : FAIL) + " ] Create a default tree.";
    }
    std::string tmp = (ret ? " OK " : "FAIL");
    return "[ " + tmp + " ] Create a default tree.\n";
}

/**
 * Function : testParamConstructorTree.
 * Return : std::string.
 * Description : Check the constructor with parameter of a tree.
 * */
std::string Test::testParamConstructorTree() {
    ArbreB tree(1);
    bool ret = ( (tree.getRoot()->getData() == 1)
                && (tree.getRoot()->getLeft() == nullptr)
                && (tree.getRoot()->getRight() == nullptr)
                );

    sumTest += int(ret);
    numTestGlobal += 1;
    if(inColor) {
        return "[ " + (ret ? OK : FAIL) + " ] Create a tree with the value of the root.";
    }
    std::string tmp = (ret ? " OK " : "FAIL");
    return "[ " + tmp + " ] Create a tree with the value of the root.\n";
}

/**
 * Function : testAssignTree
 * Return : std::string.
 * Description : Check if the copy of a tree in another is a success.
 * */
std::string Test::testAssignTree() {
    ArbreB tree(2);
    tree << 4;
    tree << 6;
    tree << 8;
    tree << 10;
    ArbreB tree2;
    tree2 = tree;
    bool ret = (tree == tree2);

    sumTest += int(ret);
    numTestGlobal +=1;
    if(inColor) {
        return "[ " + (ret ? OK : FAIL) + " ] Assign a tree in a other.";
    }
    std::string tmp = (ret ? " OK " : "FAIL");
    return "[ " + tmp + " ] Assign a tree in a other.\n";
}

/**
 * Function : testEqualsTree.
 * Return : std::string.
 * Description : Check if two are equals (same nodes, sames size, same depth).
 * */
std::string Test::TestEqualsTree() {
    std::string retStr, retStr2, tmp;

    // Test with empty tree
    ArbreB emptyTree;
    ArbreB emptyTree2;
    bool ret1 = (emptyTree == emptyTree2);
    if(inColor) {
        retStr = "\t[ " + (ret1 ? OK : FAIL) + " ] Two empty trees equals.\n";
    }
    else {
        tmp = (ret1 ? " OK " : "FAIL");
        retStr2 = "\t[ " + tmp + " ] Two empty trees equals.\n";
    }

    // Test one empty and one full
    ArbreB tree(2);
    tree.getRoot()->setLeft(4);
    tree.getRoot()->setRight(6);
    tree.getRoot()->getLeft()->setLeft(8);
    tree.getRoot()->getLeft()->setRight(10);
    tree.getRoot()->getRight()->setLeft(12);
    bool ret2 = ((emptyTree == tree) == false);
    if(inColor) {
        retStr += "\t[ " + (ret2 ? OK : FAIL) + " ] One empty and one full.\n";
    }
    else {
        tmp = (ret2 ? " OK " : "FAIL");
        retStr2 += "\t[ " + tmp + " ] One empty and one full.\n";
    }

    // Test two full trees equals
    ArbreB tree2(2);
    tree2.getRoot()->setLeft(4);
    tree2.getRoot()->setRight(6);
    tree2.getRoot()->getLeft()->setLeft(8);
    tree2.getRoot()->getLeft()->setRight(10);
    tree2.getRoot()->getRight()->setLeft(12);
    bool ret3 = (tree == tree2);
    if(inColor) {
        retStr += "\t[ " + (ret3 ? OK : FAIL) + " ] Two full trees equals.\n";
    }
    else {
        tmp = (ret3 ? " OK " : "FAIL");
        retStr2 += "\t[ " + tmp + " ] Two full trees equals.\n";
    }

    // Return all sub tests
    bool ret = ret1 & ret2 & ret3;
    sumTest += int(ret);
    numTestGlobal +=1;
    if(inColor) {
        return retStr + "[ " + (ret ? OK : FAIL) + " ] Say if two tree are equals.";
    }
    tmp = (ret ? " OK " : "FAIL");
    return retStr2 + "[ " + tmp + " ] Say if two tree are equals.\n";
}

/**
 * Function : testAdd.
 * Return : std::string.
 * Description : Check if we can add a node in a tree.
 * */
std::string Test::testAdd() {
    ArbreB tree(2);
    tree << 3;
    bool ret = ( (tree.getRoot()->getLeft() && tree.getRoot()->getLeft()->getData() == 3)
                || (tree.getRoot()->getRight() && tree.getRoot()->getRight()->getData() == 3)
                );
    
    sumTest += int(ret);
    numTestGlobal += 1;
    if(inColor) {
        return "[ " + (ret ? OK : FAIL) + " ] Add a new node in the tree.";
    }
    std::string tmp = (ret ? " OK " : "FAIL");
    return "[ " + tmp + " ] Add a new node in the tree.\n";
}

/**
 * Function : testDell.
 * Return : std::string.
 * Description : Check if deletion on a node is a success.
 * */
std::string Test::testDell() {
    std::string retStr, retStr2, tmp;

    // Test delete the node
    ArbreB tree(1);
    tree >> 1;
    bool ret1 = (!tree.getRoot());
    if(inColor) {
        retStr = "\t[ " + (ret1 ? OK : FAIL) + " ] Dell root in empty tree.\n";
    }
    else {
        tmp = (ret1 ? " OK " : "FAIL");
        retStr2 = "\t[ " + tmp + " ] Dell root in empty tree.\n";
    }

    // Test delete the root in tree with one children
    ArbreB tree2(1);
    tree2 << 2;
    tree2 >> 1;
    ArbreB res2(2);
    bool ret2 = (tree2 == res2);
    if(inColor) {
        retStr += "\t[ " + (ret2 ? OK : FAIL) + " ] Dell root in tree with one children.\n";
    }
    else {
        tmp = (ret2 ? " OK " : "FAIL");
        retStr2 += "\t[ " + tmp + " ] Dell root in tree with one children.\n";
    }

    // Test delete the root in tree with child
    ArbreB tree3(1);
    tree3.getRoot()->setLeft(2);
    tree3.getRoot()->setRight(3);
    tree3.getRoot()->getLeft()->setLeft(4);
    tree3 >> 1;
    bool ret3 = ( (tree3.getRoot()->getData() == 2) 
                || (tree3.getRoot()->getData() == 3)
                || (tree3.getRoot()->getData() == 4)
                );
    if(inColor) {
        retStr += "\t[ " + (ret3 ? OK : FAIL) + " ] Dell root in tree with child.\n";
    }
    else {
        tmp = (ret3 ? " OK " : "FAIL");
        retStr2 += "\t[ " + tmp + " ] Dell root in tree with child.\n";
    }

    // test delete the root in the millde of the tree
    ArbreB tree4(1);
    tree4.getRoot()->setLeft(2);
    tree4.getRoot()->setRight(3);
    tree4.getRoot()->getLeft()->setLeft(4);
    tree4.getRoot()->getLeft()->setRight(5);
    tree4.getRoot()->getRight()->setLeft(6);
    tree4.getRoot()->getRight()->setRight(7);
    tree4 >> 3;
    ArbreB res4(1);
    res4.getRoot()->setLeft(2);
    res4.getRoot()->setRight(4);
    res4.getRoot()->getLeft()->setRight(5);
    res4.getRoot()->getRight()->setLeft(6);
    res4.getRoot()->getRight()->setRight(7);
    bool ret4 = false;
    if(inColor) {
        retStr += "\t[ " + (ret4 ? OK : FAIL) + " ] Dell root in the millde of the tree.\n";
    }
    else {
        tmp = (ret4 ? " OK " : "FAIL");
        retStr2 += "\t[ " + tmp + " ] Dell root in the millde of the tree.\n";
    }

    // Return all sub test
    bool ret = ret1 & ret2 & ret3 & ret4;
    sumTest += int(ret);
    numTestGlobal += 1;
    if(inColor) {
        return retStr + "[ " + (ret ? OK : FAIL) + " ] Delete a node in the tree.";
    }
    tmp = (ret ? " OK ": "FAIL");
    return retStr2 + "[ " + tmp + " ] Delete a node in the tree.\n";
}

/**
 * Function : testFind.
 * Return : std::string.
 * Description : Check if we can find a specific node by his value in the tree.
 * */
std::string Test::testFind() {
    std::string retStr, retStr2, tmp;

    // Test find a value in the middle of the tree
    ArbreB tree(1);
    tree << 2;
    tree << 3;
    tree << 4;
    tree << 5;
    tree << 6;
    Sommet* tryFind = tree.find(tree.getRoot(), 3);
    bool ret1 = (tryFind->getData() == 3);
    if(inColor) {
     retStr = "\t[ " + (ret1 ? OK : FAIL) + " ] Find value in middle the tree.\n";
    }
    else {
        tmp = (ret1 ? " OK " : "FAIL");
        retStr2 = "\t[ " + tmp + " ] Find value in middle the tree.\n";
    }

    // Test find value not in the tree
    Sommet* tryFind2 = tree.find(tree.getRoot(), 0);
    bool ret2 = (!tryFind2);
    if(inColor) {
     retStr += "\t[ " + (ret2 ? OK : FAIL) + " ] Find value not in the tree.\n";
    }
    else {
        tmp = (ret2 ? " OK " : "FAIL");
        retStr2 += "\t[ " + tmp + " ] Find value not in the tree.\n";
    }

    // Test find the root value of the tree 
    Sommet* tryFind3 = tree.find(tree.getRoot(), 1);
    bool ret3 = (tryFind3->getData() == 1);
    if(inColor) {
     retStr += "\t[ " + (ret3 ? OK : FAIL) + " ] Find root value of the tree.\n";
    }
    else {
        tmp = (ret3 ? " OK " : "FAIL");
        retStr2 += "\t[ " + tmp + " ] Find root value of the tree.\n";
    }

    // Return all sub tests
    bool ret = ret1 & ret2 & ret3;
    sumTest += int(ret);
    numTestGlobal +=1;
    if(inColor) {
        return retStr + "[ " + (ret ? OK : FAIL) + " ] Say if a value is in the tree.";
    }
    tmp = (ret ? " OK " : "FAIL");
    return retStr2 + "[ " + tmp + " ] Say if a value is in the tree.\n";
}

/**
 * Function : testGetNodeAtIndex.
 * Return : std::string.
 * Description : Check if we can find a specific node by his position in the tree.
 * */
std::string Test::testGetNodeAtIndex() {
    ArbreB tree(1);
    tree.getRoot()->setLeft(2);
    tree.getRoot()->setRight(3);
    tree.getRoot()->getLeft()->setLeft(4);
    tree.getRoot()->getLeft()->setRight(5);
    tree.getRoot()->getRight()->setLeft(6);
    
    bool ret = (tree[3]->getData() == 3);
    sumTest += int(ret);
    numTestGlobal += 1;
    if(inColor) {
        return "[ " + (ret ? OK : FAIL) + " ] Get node at index in the tree.";
    }
    std::string tmp = (ret ? " OK " : "FAIL");
    return "[ " + tmp + " ] Get node at index in the tree.\n";
}

/**
 * Function : testJoin.
 * Return : 'std::string'.
 * Description : Check if we can make a fusion with two trees.
 * */
std::string Test::testJoin() {
    ArbreB tree(2);
    tree.getRoot()->setLeft(4);
    tree.getRoot()->setRight(6);
    tree.getRoot()->getLeft()->setLeft(8);
    tree.getRoot()->getLeft()->setRight(10);

    ArbreB tree2(1);
    tree2.getRoot()->setLeft(3);
    tree2.getRoot()->setRight(5);
    tree2.getRoot()->getLeft()->setLeft(7);
    tree2.getRoot()->getLeft()->setRight(11);

    tree += tree2;

    ArbreB res(3);
    res.getRoot()->setLeft(2);
    res.getRoot()->getLeft()->setLeft(4);
    res.getRoot()->getLeft()->setRight(6);
    res.getRoot()->getLeft()->getLeft()->setLeft(8);
    res.getRoot()->getLeft()->getLeft()->setRight(10);
    res.getRoot()->setRight(1);
    res.getRoot()->getRight()->setLeft(3);
    res.getRoot()->getRight()->setRight(5);
    res.getRoot()->getRight()->getLeft()->setLeft(7);
    res.getRoot()->getRight()->getLeft()->setRight(11);

    bool ret = ((tree == res) == true);
    sumTest += int(ret);
    numTestGlobal +=1;
    if(inColor) {
        return "[ " + (ret ? OK : FAIL) + " ] Join the tree with a other.";
    }
    std::string tmp = (ret ? " OK " : "FAIL");
    return "[ " + tmp + " ] Join the tree with a other.\n";
}

/**
 * Function : testGetNodeAtIndex.
 * Return : std::string.
 * Description : Check if we can make a split of a tree. We should have two trees at the end.
 * */
std::string Test::testSplit() {
    ArbreB tree(3);
    tree.getRoot()->setLeft(2);
    tree.getRoot()->getLeft()->setLeft(4);
    tree.getRoot()->getLeft()->setRight(6);
    tree.getRoot()->getLeft()->getLeft()->setLeft(8);
    tree.getRoot()->getLeft()->getLeft()->setRight(10);
    tree.getRoot()->setRight(1);
    tree.getRoot()->getRight()->setLeft(3);
    tree.getRoot()->getRight()->setRight(5);
    tree.getRoot()->getRight()->getLeft()->setLeft(7);
    tree.getRoot()->getRight()->getLeft()->setRight(11);

    ArbreB tree2;
    tree -= tree2;

    ArbreB res(1);
    res.getRoot()->setLeft(3);
    res.getRoot()->setRight(5);
    res.getRoot()->getLeft()->setLeft(7);
    res.getRoot()->getLeft()->setRight(11);

    bool ret = ((tree2 == res) == true);
    sumTest += int(ret);
    numTestGlobal +=1;
    if(inColor) {
        return "[ " + (ret ? OK : FAIL) + " ] Split the tree in two.";
    }
    else {
        std::string tmp = (ret ? " OK " : "FAIL");
        return "[ " + tmp + " ] Split the tree in two.\n";
    }
}
/* End Tree.hpp */

/* Test Parser.hpp */
// void Test::testCalculFreqChar() {
//     std::vector<int> freq = {'h', 1, 'e', 1, 'l', 3, 'o', 2, ' ', 1, 'w', 1, 'r', 1, 'd', 1};

//     Parser parser;
//     std::vector<int> freq2;
//     parser.freqChar("textTest.txt", freq2);

//     for(int i = 0; i < 9; ++i) {
//         if(freq[i] != freq2[i]) {
//         return;
//         }
//     }
//     return;
// }
/* End Parser.hpp */

/* Getters */
int Test::getSumTest() const {
    return sumTest;
}

int Test::getNumTestGlobal() const {
    return numTestGlobal;
}
/* End getters */