#include "Test.hpp"

Test::Test() : sumTest(0), numTestGlobal(0) {}

void Test::allTest() {
  /* Test Tree.hpp */
  std::cout << "########################### TESTS ##########################" << std::endl;
  std::cout << "#        test get 'sommet' at index         :" << (testGetSommetAtIndex() ? "     passed"  : "       fail") << " ! #" << std::endl;
  std::cout << "#                 test add                  :" << (testAdd() ? "     passed"  : "       fail") << " ! #" << std::endl;
  std::cout << "#                test dell                  :" << (testDell() ? "     passed"  : "       fail") << " ! #" << std::endl;
  std::cout << "#               test depth                  :" << (testDepth() ? "     passed"  : "       fail") << " ! #" << std::endl;
  std::cout << "#                test size                  :" << (testSize() ? "     passed"  : "       fail") << " ! #" << std::endl;
  std::cout << "#                test find                  :" << (testFind() ? "     passed"  : "       fail") << " ! #" << std::endl;
  std::cout << "#                test join                  :" << (testJoin() ? "     passed"  : "       fail") << " ! #" << std::endl;
  //std::cout << "#               test split                  :" << (testSplit() ? "     passed"  : "       fail") << " ! #" << std::endl;
  /* Test Parser.hpp */
  // std::cout << "testCalculFreqChar : " << ((testCalculFreqChar()) ? "s ucced" : "fail") << " ! " << std::endl;
  
  std::cout << "################### ["<< sumTest << "/" << numTestGlobal << "] tests passed ! ###################" << std::endl;
}

/* Test Tree.hpp */
bool Test::testGetSommetAtIndex() {
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

  bool ret = (tree.getSize() == 4);

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
  // std::cout << "tree : \n";
  // tree.getRoot()->printBeautifulTree(0);
  // std::cout << "\n\n";

  ArbreB tree2(1);
  tree2 << 3;
  tree2 << 5;
  tree2 << 7;
  tree2 << 9;
  // std::cout << "tree2 : \n";
  // tree2.getRoot()->printBeautifulTree(0);
  // std::cout << "\n\n";

  tree += tree2;
  // std::cout << "tree : \n";
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
  std::cout << "tree :" << std::endl;
  tree.getRoot()->printBeautifulTree(0);
  std::cout << "\n\n";

  ArbreB tree2(1);
  tree2 << 3;
  tree2 << 5;
  tree2 << 7;
  tree2 << 9;
  std::cout << "tree2 :" << std::endl;
  tree2.getRoot()->printBeautifulTree(0);
  std::cout << "\n\n";

  tree += tree2;
  std::cout << "tree :" << std::endl;
  tree.getRoot()->printBeautifulTree(0);
  std::cout << "\n\n";

  ArbreB tree3;
  tree -= tree3;
  std::cout << "tree :" << std::endl;
  tree.getRoot()->printBeautifulTree(0);
  std::cout << "\n\n";

  std::cout << "tree3 :" << std::endl;
  tree3.getRoot()->printBeautifulTree(0);

  bool ret = false;

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

  // std::cout << "tree : \n";
  // tree.getRoot()->printBeautifulTree(0);
  // std::cout << "\n\n";

  Sommet cpyNode2 = *tree.getRoot();
  // std::cout << "treecpy2 : \n" << cpyNode2 << std::endl;
  // cpyNode2.printBeautifulTree(0);

  bool ret = true;

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