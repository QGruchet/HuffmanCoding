#include "Test.hpp"

Test::Test() : sumTest(0), numTestGlobal(0) {}

void Test::allTest() {
  /* Test Tree */
  std::cout << "\n\t> TESTS <" << std::endl;
  std::cout << "[ " << (testGetNodeAtIndex() ? " \033[0;32mOK\033[0m "  : "\033[0;31mFAIL\033[0m") << " ] Get node at index." << std::endl;
  std::cout << "[ " << (testAdd() ? " \033[0;32mOK\033[0m "  : "\033[0;31mFAIL\033[0m") << " ] Add a new node in the tree." << std::endl;
  std::cout << "[ " << (testDell() ? " \033[0;32mOK\033[0m "  : "\033[0;31mFAIL\033[0m") << " ] Delete a node in the tree." << std::endl;
  std::cout << "[ " << (testDepth() ? " \033[0;32mOK\033[0m "  : "\033[0;31mFAIL\033[0m") << " ] Count the tree's depht." << std::endl;
  std::cout << "[ " << (testSize() ? " \033[0;32mOK\033[0m "  : "\033[0;31mFAIL\033[0m") << " ] Count the number of nodes." << std::endl;
  std::cout << "[ " << (testFind() ? " \033[0;32mOK\033[0m "  : "\033[0;31mFAIL\033[0m") << " ] Say if a value is in the tree." << std::endl;
  std::cout << "[ " << (testJoin() ? " \033[0;32mOK\033[0m "  : "\033[0;31mFAIL\033[0m") << " ] Join the tree with a other." << std::endl;
  std::cout << "[ " << (testSplit() ? " \033[0;32mOK\033[0m "  : "\033[0;31mFAIL\033[0m") << " ] Split the tree in two." << std::endl;
  std::cout << "[ " << (testAssignTree() ? " \033[0;32mOK\033[0m "  : "\033[0;31mFAIL\033[0m") << " ] Assign the tree in a other empty tree." << std::endl;
  std::cout << "[ " << (TestEqualsTree() ? " \033[0;32mOK\033[0m "  : "\033[0;31mFAIL\033[0m") << " ] Say if two tree are equals." << std::endl;
  /* Test Parser */
  // std::cout << "testCalculFreqChar : " << ((testCalculFreqChar()) ? "s ucced" : "fail") << " ! " << std::endl;
  
  if(sumTest == numTestGlobal) {
    std::cout << ">TESTS RESULT : \033[0;31m" << sumTest << "\033[0m / << \033[0;32m" << numTestGlobal << "\033[0m ] tests passed ! <\n" << std::endl;
  }
  else {
    std::cout << ">TESTS RESULT : \033[0;31m" << sumTest << "\033[0m / << \033[0;32m" << numTestGlobal << "\033[0m ] tests passed ! <\n" << std::endl;
  }
}

/* Test Tree.hpp */
bool Test::testGetNodeAtIndex() {
  ArbreB tree(1);

  tree << 2;
  tree << 3;
  tree << 4;
  tree << 5;
  tree << 6;

  // std::cout<< tree[3]->getData() << std::endl;
  // std::cout<< tree[5]->getData() << std::endl;
  
  bool ret = 1;

  sumTest += int(ret);
  numTestGlobal += 1;

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

bool Test::testCopy() {
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

  bool ret = true;

  sumTest += int(ret);
  numTestGlobal +=1;

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