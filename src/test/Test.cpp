#include "Test.hpp"

Test::Test() : sumTest(0), numTestSucced(0) {}

void Test::allTest() {
  /* Test Tree.hpp */
  std::cout << "########################### TESTS ##########################" << std::endl;
  std::cout << "#      test default builder 'sommet'        :" << (testDefaultBuilderSommet() ? "     passed"  : "       fail") << " ! #" << std::endl;
  std::cout << "#     test builder 'sommet' with data       :" << (testBuilderSommetWithData() ? "     passed"  : "       fail") << " ! #" << std::endl;
  std::cout << "#        test copy builder 'sommet'         :" << (testCopyBuilderSommet() ? "     passed"  : "       fail") << " ! #" << std::endl;
  std::cout << "#      test default builder 'arbreB'        :" << (testDefaultBuilderArbreB() ? "     passed"  : "       fail") << " ! #" << std::endl;
  std::cout << "#     test builder 'arbreB' with data       :" << (testBuilderArbreBWithData() ? "     passed"  : "       fail") << " ! #" << std::endl;
  std::cout << "#        test copy builder 'arbreB'         :" << (testCopyBuilderArbreB() ? "     passed"  : "       fail") << " ! #" << std::endl;
  std::cout << "#        test get 'sommet' at index         :" << (testGetSommetAtIndex() ? "     passed"  : "       fail") << " ! #" << std::endl;
  std::cout << "#                 test add                  :" << (testAdd() ? "     passed"  : "       fail") << " ! #" << std::endl;
  std::cout << "#               test depth                  :" << (testDepth() ? "     passed"  : "       fail") << " ! #" << std::endl;
  std::cout << "#                test size                  :" << (testSize() ? "     passed"  : "       fail") << " ! #" << std::endl;
  std::cout << "#                test dell                  :" << (testDell() ? "     passed"  : "       fail") << " ! #" << std::endl;
  /* Test Parser.hpp */
  // std::cout << "testCalculFreqChar : " << ((testCalculFreqChar()) ? "s ucced" : "fail") << " ! " << std::endl;
  
  std::cout << "################### ["<< sumTest << "/" << numTestSucced << "] tests passed ! ###################" << std::endl;
}

/* Test Tree.hpp */
bool Test::testDefaultBuilderSommet() {
  Sommet node;

  bool ret = ( (node.getData() == 0)
          && (node.getLeft() == nullptr)
          && (node.getRight() ==  nullptr) );

  sumTest += int(ret);
  numTestSucced += 1;

  return ret;
}

bool Test::testDefaultBuilderArbreB() {
  ArbreB tree;

  bool ret = (tree.getRoot() == nullptr);

  sumTest += int(ret);
  numTestSucced += 1;

  return ret;
}

bool Test::testBuilderSommetWithData() {
  Sommet node(2);

  bool ret = ( (node.getData() == 2)
          && (node.getLeft() == nullptr)
          && (node.getRight() ==  nullptr) );

  sumTest += int(ret);
  numTestSucced += 1;

  return ret;
}

bool Test::testCopyBuilderSommet() {
  bool ret = 0;

  sumTest += int(ret);
  numTestSucced += 1;

  return ret;
}

bool Test::testBuilderArbreBWithData() {
  ArbreB tree(2);
  Sommet* root = tree.getRoot();

  bool ret = ( (root->getData() == 2)
          && (root->getLeft() == nullptr)
          && (root->getRight() ==  nullptr) );

  sumTest += int(ret);
  numTestSucced += 1;

  return ret;
}

bool Test::testCopyBuilderArbreB() {
  bool ret = 0;

  sumTest += int(ret);
  numTestSucced += 1;

  return ret;
}

bool Test::testGetSommetAtIndex() {
  bool ret = 0;

  sumTest += int(ret);
  numTestSucced += 1;

  return ret;
}

bool Test::testAdd() {
  std::srand((unsigned int)time(0));
  ArbreB tree(2);
  tree << 3;
  
  bool ret = ( (tree.getRoot()->getLeft() && tree.getRoot()->getLeft()->getData() == 3)
              || (tree.getRoot()->getRight() && tree.getRoot()->getRight()->getData() == 3));

  sumTest += int(ret);
  numTestSucced += 1;

  return ret;
}

bool Test::testDepth() {
  bool ret = 0;

  sumTest += int(ret);
  numTestSucced += 1;

  return ret;
}

bool Test::testSize() {
  bool ret = 0;

  sumTest += int(ret);
  numTestSucced += 1;

  return ret;
}

bool Test::testDell() {
  bool ret = 0;

  sumTest += int(ret);
  numTestSucced += 1;

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