#include "Test.hpp"

Test::Test() : sumTest(0), numTestSucced(0) {}

void Test::allTest() {
  /* Test Tree.hpp */
  std::cout << "########################## TESTS #########################" << std::endl;
  std::cout << "#      test default builder 'sommet'        :" << (testDefaultBuilderSommet() ? "     succes"  : "       fail") << " ! #" << std::endl;
  std::cout << "#        test copy builder 'sommet'         :" << (testCopyBuilderSommet() ? "     succes"  : "       fail") << " ! #" << std::endl;
  std::cout << "#      test default builder 'arbreB'        :" << (testDefaultBuilderArbreB() ? "     succes"  : "       fail") << " ! #" << std::endl;
  std::cout << "#        test copy builder 'arbreB'         :" << (testCopyBuilderArbreB() ? "     succes"  : "       fail") << " ! #" << std::endl;
  std::cout << "# test builder 'sommet' with numCar and car :" << (testBuilderSommetWithNumCarAndCar() ? "     succes"  : "       fail") << " ! #" << std::endl;
  std::cout << "#      test builder 'sommet' with num       :" << (testBuilderSommetWithNum() ? "     succes"  : "       fail") << " ! #" << std::endl;
  std::cout << "#     test builder 'arbreB' with param      :" << (testBuilderArbreBWithParam() ? "     succes"  : "       fail") << " ! #" << std::endl;
  std::cout << "#        test get 'sommet' at index         :" << (testGetSommetAtIndex() ? "     succes"  : "       fail") << " ! #" << std::endl;
  std::cout << "#                test add                 :" << (testAdd() ? "     succes"  : "       fail") << " ! #" << std::endl;
  std::cout << "#              test depth                 :" << (testDepth() ? "     succes"  : "       fail") << " ! #" << std::endl;
  std::cout << "#               test size                 :" << (testSize() ? "     succes"  : "       fail") << " ! #" << std::endl;
  std::cout << "#        test dell node at index          :" << (testDellNodeAtIndex() ? "     succes"  : "       fail") << " ! #" << std::endl;
  std::cout << "#            test create dot              :" << (createDot() ? "     succes"  : "       fail") << " ! #" << std::endl;

  /* Test Parser.hpp */
  // std::cout << "testCalculFreqChar : " << ((testCalculFreqChar()) ? "s ucced" : "fail") << " ! " << std::endl;
  
  std::cout << "################### [";
  std::cout << sumTest << "/" << numTestSucced << " tests passed !] ##################" << std::endl;
}

/* Test Tree.hpp */
bool Test::testDefaultBuilderSommet() {
  Sommet node;

  bool ret = ( (node.getNumCar() == -1)
          && (node.getCar() == '\0')
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

bool Test::testCopyBuilderSommet() {
  bool ret = 0;

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

bool Test::testBuilderSommetWithNumCarAndCar() {
  Sommet node(2, 'e');

  bool ret = ( (node.getNumCar() == 2)
          && (node.getCar() == 'e')
          && (node.getLeft() == nullptr)
          && (node.getRight() ==  nullptr) );

  sumTest += int(ret);
  numTestSucced += 1;

  return ret;
}

bool Test::testBuilderSommetWithNum() {
  Sommet node(2);

  bool ret = ( (node.getNumCar() == 2)
          && (node.getCar() == '\0')
          && (node.getLeft() == nullptr)
          && (node.getRight() ==  nullptr) );

  sumTest += int(ret);
  numTestSucced += 1;

  return ret;
}

bool Test::testBuilderArbreBWithParam() {
  Sommet* node = new Sommet(2, 'e');
  ArbreB tree(node);
  Sommet* root = tree.getRoot();

  bool ret = ( (root->getNumCar() == 2)
          && (root->getCar() == 'e')
          && (root->getLeft() == nullptr)
          && (root->getRight() ==  nullptr) );

  sumTest += int(ret);
  numTestSucced += 1;

  return ret;
}

bool Test::testGetSommetAtIndex() {
  srand((unsigned int)time(0));
  Sommet *root = new Sommet(1);
  ArbreB tree(root);
  *root << 2;
  *root << 0;
  *root << 3;

  bool ret = 0;

  sumTest += int(ret);
  numTestSucced += 1;

  return ret;
}

bool Test::testAdd() {
  srand((unsigned int)time(0));
  Sommet* root = new Sommet(2);
  ArbreB tree(root);

  *root << 3;
  *root << 1;
  *root << 13;
  *root << 6;
  *root << 0;
  *root << 3;
  *root << 5;
  *root << 69;
  
  bool ret = 1;

  sumTest += int(ret);
  numTestSucced += 1;

  return ret;
}

bool Test::testDepth() {
  srand((unsigned int)time(0));
  Sommet *root = new Sommet(1);
  ArbreB tree(root);
  *root << 2;
  *root << 0;
  *root << 3;

  bool ret = (root->getDepth() == 3);

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

bool Test::testDellNodeAtIndex() {
  bool ret = 0;

  sumTest += int(ret);
  numTestSucced += 1;

  return ret;
}

bool Test::createDot() {
  srand((unsigned int)time(0));
  Sommet *root = new Sommet(2);
  *root << 5;
  *root << 1;
  *root << 7;
  *root << 6;
  *root << 4;
  *root << 0;
  root->ecritureHeader();
  root->ecritureFichier(root);
  root->ecritureEnder();

  bool ret = 1;

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