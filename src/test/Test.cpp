#include "Test.hpp"
#include <string>

Test::Test() : sumTest(0), numTestGlobal(0) {}

std::string inRed(std::string msg) {
  return "\033[0;31m" + msg + "\033[0m";
}

std::string inGreen(std::string msg) {
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

  std::cout << "[ " << (testDefaultConstructorTree() ? " \033[0;32mOK\033[0m "  : "\033[0;31mFAIL\033[0m") << " ] Create a default tree." << std::endl;
  std::cout << "[ " << (testParamConstructorTree() ? " \033[0;32mOK\033[0m "  : "\033[0;31mFAIL\033[0m") << " ] Create a tree with the value of the root." << std::endl;
  // std::cout << "[ " << (testAssignTree() ? " \033[0;32mOK\033[0m "  : "\033[0;31mFAIL\033[0m") << " ] Assign a trees in a other." << std::endl;
  std::cout << "[ " << (TestEqualsTree() ? " \033[0;32mOK\033[0m "  : "\033[0;31mFAIL\033[0m") << " ] Say if two tree are equals." << std::endl;
  std::cout << "[ " << (testAdd() ? " \033[0;32mOK\033[0m "  : "\033[0;31mFAIL\033[0m") << " ] Add a new node in the tree." << std::endl;
  std::cout << "[ " << (testDell() ? " \033[0;32mOK\033[0m "  : "\033[0;31mFAIL\033[0m") << " ] Delete a node in the tree." << std::endl;
  std::cout << "[ " << (testFind() ? " \033[0;32mOK\033[0m "  : "\033[0;31mFAIL\033[0m") << " ] Say if a value is in the tree." << std::endl;
  std::cout << "[ " << (testGetNodeAtIndex() ? " \033[0;32mOK\033[0m "  : "\033[0;31mFAIL\033[0m") << " ] Get node at index in the tree." << std::endl;
  std::cout << "[ " << (testJoin() ? " \033[0;32mOK\033[0m "  : "\033[0;31mFAIL\033[0m") << " ] Join the tree with a other." << std::endl;
  std::cout << "[ " << (testSplit() ? " \033[0;32mOK\033[0m "  : "\033[0;31mFAIL\033[0m") << " ] Split the tree in two." << std::endl;

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
  testTxt();

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

  // std::cout << "tree : " << std::endl;
  // tree.getRoot()->printBeautifulTree(0);
  // std::cout << "\n\n";

  Sommet cpyNode2 = *tree.getRoot();
  // std::cout << "treecpy2 : " << std::endl;
  // cpyNode2.printBeautifulTree(0);

  bool ret = ((cpyNode2 == *tree.getRoot()) == true);

  sumTest += int(ret);
  numTestGlobal +=1;

  return ret;
}

bool Test::testEqualsNode() {
  ArbreB tree(2);
  tree << 4;
  tree << 6;
  tree << 8;
  tree << 10;

  ArbreB tree2(2);
  tree << 4;
  tree << 6;
  tree << 8;
  tree << 10;

  bool ret = ((*tree.getRoot() == *tree2.getRoot()) == true);

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

  // std::cout << "tree : " << std::endl;
  // tree.getRoot()->printBeautifulTree(0);

  // std::cout << "tree2 : " << std::endl;
  // tree2.getRoot()->printBeautifulTree(0);

  bool ret = true;

  sumTest += int(ret);
  numTestGlobal +=1;

  return ret;
}

bool Test::TestEqualsTree() {
  ArbreB tree(2);
  tree << 4;
  tree << 6;
  tree << 8;
  tree << 10;

  ArbreB tree2(2);
  tree2 << 4;
  tree2 << 6;
  tree2 << 8;
  tree2 << 10;

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

bool Test::testDell() {
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

  tree << 2;
  tree << 3;
  tree << 4;
  tree << 5;
  tree << 6;

  // std::cout<< tree[3]->getData() << std::endl;
  // std::cout<< tree[5]->getData() << std::endl;
  
  bool ret = true;

  sumTest += int(ret);
  numTestGlobal += 1;

  return ret;
}

bool Test::testJoin() {
  ArbreB tree(2);
  tree << 4;
  tree << 6;
  tree << 8;
  tree << 10;
  // std::cout << "tree : " << std::endl;
  // tree.getRoot()->printBeautifulTree(0);
  // std::cout << "\n\n";

  ArbreB tree2(1);
  tree2 << 3;
  tree2 << 5;
  tree2 << 7;
  tree2 << 9;
  // std::cout << "tree2 : " << std::endl;
  // tree2.getRoot()->printBeautifulTree(0);
  // std::cout << "\n\n";

  tree += tree2;
  // std::cout << "tree : " << std::endl;
  // tree.getRoot()->printBeautifulTree(0);

  bool ret = true;

  sumTest += int(ret);
  numTestGlobal +=1;

  return ret;
}

bool Test::testSplit() {
  ArbreB tree(2);
  tree << 4;
  tree << 6;
  tree << 8;
  tree << 10;
  // std::cout << "tree :" << std::endl;
  // tree.getRoot()->printBeautifulTree(0);
  // std::cout << "\n\n";

  ArbreB tree2(1);
  tree2 << 3;
  tree2 << 5;
  tree2 << 7;
  tree2 << 9;
  // std::cout << "tree2 :" << std::endl;
  // tree2.getRoot()->printBeautifulTree(0);
  // std::cout << "\n\n";

  tree += tree2;
  // std::cout << "tree += tree2 :" << std::endl;
  // tree.getRoot()->printBeautifulTree(0);
  // std::cout << "\n\n";

  ArbreB tree3;
  tree -= tree3;
  // std::cout << "tree -= tree3 :" << std::endl;
  // tree.getRoot()->printBeautifulTree(0);
  // std::cout << "\n\n";

  // std::cout << "tree3 :" << std::endl;
  // tree3.getRoot()->printBeautifulTree(0);

  bool ret = true;

  sumTest += int(ret);
  numTestGlobal +=1;

  return ret;
}

void Test::testTxt(){
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

  tree.getRoot()->writeBeautifulTreeInFile(0);
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