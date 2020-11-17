#include "Test.hpp"
#include <string>

Test::Test() : sumTest(0), numTestGlobal(0) {}

std::string Test::inRed(std::string msg) {
  return "\033[0;31m" + msg + "\033[0m";
}

std::string Test::inGreen(std::string msg) {
  return "\033[0;32m" + msg + "\033[0m";
} 

void Test::allTest() {
  std::string OK = " " + inGreen("OK") + " ";
  std::string FAIL = inRed("FAIL");

  /* Test Tree */
  // Sommet
  std::cout << "\n\t> TESTS <" << std::endl;
  std::cout << "[ " << (testDefaultConstructorNode() ? OK : FAIL) << " ] Create a default node." << std::endl;
  std::cout << "[ " << (testCopyConstructorNode() ? OK : FAIL) << " ] Create a node with a copy." << std::endl;
  std::cout << "[ " << (testParamConstructorNode() ? OK : FAIL) << " ] Create a node with a value." << std::endl;
  std::cout << "[ " << (testAssignNode() ? OK : FAIL) << " ] Assign a node in a other ." << std::endl;
  std::cout << "[ " << (testEqualsNode() ? OK : FAIL) << " ] Say if two nodes are equals." << std::endl;
  std::cout << "[ " << (testDepth() ? OK : FAIL) << " ] Count the tree's depht." << std::endl;
  std::cout << "[ " << (testSize() ? OK : FAIL) << " ] Count the number of nodes." << std::endl;

  // ArbreB
  std::cout << "[ " << (testDefaultConstructorTree() ? OK : FAIL) << " ] Create a default tree." << std::endl;
  std::cout << "[ " << (testParamConstructorTree() ? OK : FAIL) << " ] Create a tree with the value of the root." << std::endl;
  std::cout << "[ " << (testAssignTree() ? OK : FAIL) << " ] Assign a trees in a other." << std::endl;
  std::cout << "[ " << (TestEqualsTree() ? OK : FAIL) << " ] Say if two tree are equals." << std::endl;
  std::cout << "[ " << (testAdd() ? OK : FAIL) << " ] Add a new node in the tree." << std::endl;
  std::cout << "[ " << (testDell() ? OK : FAIL) << " ] Delete a node in the tree." << std::endl;
  std::cout << "[ " << (testFind() ? OK : FAIL) << " ] Say if a value is in the tree." << std::endl;
  std::cout << "[ " << (testGetNodeAtIndex() ? OK : FAIL) << " ] Get node at index in the tree." << std::endl;
  std::cout << "[ " << (testJoin() ? OK : FAIL) << " ] Join the tree with a other." << std::endl;
  std::cout << "[ " << (testSplit() ? OK : FAIL) << " ] Split the tree in two." << std::endl;

  // QT
  // std::cout << "[ " << (testWriteTreeInQt() ? OK : FAIL) << " ] Write the tree in QT window." << std::endl;

  /* Test Parser */
  // std::cout << "testCalculFreqChar : " << ((testCalculFreqChar()) ? "s ucced" : "fail") << " ! " << std::endl;
  
  if(sumTest == numTestGlobal) {
    std::cout << "> TESTS RESULT : [ \033[0;31m" << sumTest << "\033[0m/\033[0;32m" << numTestGlobal << "\033[0m ] tests passed ! <\n" << std::endl;
  }
  else {
    std::cout << "> TESTS RESULT : [ \033[0;31m" << sumTest << "\033[0m/\033[0;32m" << numTestGlobal << "\033[0m ] tests passed ! <\n" << std::endl;
  }
}

/* Test Tree */
// Sommet
bool Test::testDefaultConstructorNode() {
  Sommet node;

  bool ret = ( (node.getData() == 0)
            && (node.getLeft() == nullptr)
            && (node.getRight() == nullptr)
            );

  sumTest += int(ret);
  numTestGlobal += 1;

  return ret;
}

bool Test::testCopyConstructorNode() {
  Sommet node(1);

  Sommet node2(node);

  bool ret = ( (node2.getData() == node.getData())
            && (node2.getLeft() == node.getLeft())
            && (node2.getRight() == node.getRight())
            );

  sumTest += int(ret);
  numTestGlobal += 1;

  return ret;
}

bool Test::testParamConstructorNode() {
  Sommet node(1);

  bool ret = ( (node.getData() == 1)
            && (node.getLeft() == nullptr)
            && (node.getRight() == nullptr)
            );

  sumTest += int(ret);
  numTestGlobal += 1;

  return ret;
}

bool Test::testAssignNode() {
  ArbreB tree(2);
  tree << 4;
  tree << 6;
  tree << 8;
  tree << 10;

  Sommet cpyNode2 = *tree.getRoot();

  bool ret = ((cpyNode2 == *tree.getRoot()) == true);

  sumTest += int(ret);
  numTestGlobal +=1;

  return ret;
}

bool Test::testEqualsNode() {
  Sommet node(1);
  node.setLeft(2);
  node.setRight(3);
  node.getLeft()->setLeft(4);
  node.getLeft()->setRight(5);
  node.getRight()->setLeft(6);
  node.getRight()->setRight(7);

  Sommet node2(1);
  node2.setLeft(2);
  node2.setRight(3);
  node2.getLeft()->setLeft(4);
  node2.getLeft()->setRight(5);
  node2.getRight()->setLeft(6);
  node2.getRight()->setRight(7);

  bool ret = ((node == node2) == true);

  sumTest += int(ret);
  numTestGlobal +=1;

  return ret;
}

bool Test::testDepth() {
  ArbreB tree(1);

  tree << 2;
  tree << 3;
  tree << 4;

  bool ret = (tree.getRoot()->countDepth() == 3);

  sumTest += int(ret);
  numTestGlobal += 1;

  return ret;
}

bool Test::testSize() {
  ArbreB tree(1);

  tree << 2;
  tree << 3;
  tree << 4;

  bool ret = (tree.getRoot()->countSize() == 4);

  sumTest += int(ret);
  numTestGlobal += 1;

  return ret;
}

// ArbreB
bool Test::testDefaultConstructorTree() {
  ArbreB tree;

  bool ret = (tree.getRoot() == nullptr);


  sumTest += int(ret);
  numTestGlobal += 1;

  return ret;
}

bool Test::testParamConstructorTree() {
  ArbreB tree(1);

  bool ret = ( (tree.getRoot()->getData() == 1)
            && (tree.getRoot()->getLeft() == nullptr)
            && (tree.getRoot()->getRight() == nullptr)
            );

  sumTest += int(ret);
  numTestGlobal += 1;

  return ret;
}

bool Test::testAssignTree() {
  ArbreB tree(2);
  tree << 4;
  tree << 6;
  tree << 8;
  tree << 10;

  ArbreB tree2;
  tree2 = tree;

  bool ret = ((tree == tree2) == true);

  sumTest += int(ret);
  numTestGlobal +=1;

  return ret;
}

bool Test::TestEqualsTree() {
  ArbreB tree(2);
  tree.getRoot()->setLeft(4);
  tree.getRoot()->setRight(6);
  tree.getRoot()->getLeft()->setLeft(8);
  tree.getRoot()->getLeft()->setRight(10);
  tree.getRoot()->getRight()->setLeft(12);

  ArbreB tree2(2);
  tree2.getRoot()->setLeft(4);
  tree2.getRoot()->setRight(6);
  tree2.getRoot()->getLeft()->setLeft(8);
  tree2.getRoot()->getLeft()->setRight(10);
  tree2.getRoot()->getRight()->setLeft(12);

  bool ret = ((tree == tree2) == true);

  sumTest += int(ret);
  numTestGlobal +=1;

  return ret;
}

bool Test::testAdd() {
  ArbreB tree(2);
  tree << 3;
  
  bool ret = ( (tree.getRoot()->getLeft() && tree.getRoot()->getLeft()->getData() == 3)
            || (tree.getRoot()->getRight() && tree.getRoot()->getRight()->getData() == 3)
            );
  
  sumTest += int(ret);
  numTestGlobal += 1;

  return ret;
}

bool Test::testDell() { // Not finish
  ArbreB tree(1);
  // std::cout << "tree : " << tree << std::endl;
  tree >> 1; // dell root without child : ok
  // std::cout << "tree : " << tree << std::endl;

  tree << 1;
  tree << 2;
  // std::cout << "tree : " << tree << std::endl;
  tree >> 2; // dell leaf : OK
  // std::cout << "tree : " << tree << std::endl;

  tree << 2;
  // std::cout << "tree : " << tree << std::endl;
  tree >> 1; // dell root with child : 
  // std::cout << "tree : " << tree << std::endl;

  tree << 1;
  tree << 3;
  tree << 4;

  // tree.getRoot()->printBeautifulTree(0);
  // std::cout << "tree : " << tree << std::endl;
  tree >> 1;

  bool ret = false;

  sumTest += int(ret);
  numTestGlobal += 1;

  return ret;
}

bool Test::testFind() {
  ArbreB tree(1);

  tree << 2;
  tree << 3;
  tree << 4;
  tree << 5;
  tree << 6;

  Sommet* tryFind = tree.find(tree.getRoot(), 3);
  Sommet* tryFind2 = tree.find(tree.getRoot(), 0); 
  Sommet* tryFind3 = tree.find(tree.getRoot(), 5); 

  bool ret = ( (tryFind->getData() == 3) 
            && (!tryFind2)
            && (tryFind3->getData() == 5)
            );

  sumTest += int(ret);
  numTestGlobal +=1;

  return ret;
}

bool Test::testGetNodeAtIndex() {
  ArbreB tree(1);
  tree.getRoot()->setLeft(2);
  tree.getRoot()->setRight(3);
  tree.getRoot()->getLeft()->setLeft(4);
  tree.getRoot()->getLeft()->setRight(5);
  tree.getRoot()->getRight()->setLeft(6);
  
  bool ret = ((tree[3]->getData() == 3)
          && (tree[1]->getData() == 1)
            );

  sumTest += int(ret);
  numTestGlobal += 1;

  return ret;
}

bool Test::testJoin() {
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

  return ret;
}

bool Test::testSplit() { // leaks need to be delete
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

  return ret;
}

// Writer
void Test::testWriteTreeInQt(){
  ArbreB tree(2);
  tree << 4;
  tree << 6;
  tree << 8;
  tree << 10;
  tree << 2;
  tree << 7;
  tree << 4;
  tree << 28;
  tree << 0;
  tree << 4;

  Writer writer("src/txt/binary.txt");
  writer.writeBeautifulTreeInFile(tree.getRoot(), 0);
}

void Test::testWriteAllTest() {
  Writer writer("src/txt/resultTest.txt");
  // writer.write
}

/* End Tree.hpp */

/* Test Parser.hpp */
bool Test::testCalculFreqChar() {
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

/* Getters */
int Test::getSumTest() const {
  return sumTest;
}

int Test::getNumTestGlobal() const {
  return numTestGlobal;
}
/* End getters */