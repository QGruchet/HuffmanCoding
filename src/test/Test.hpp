#ifndef Test_HPP
#define Test_HPP

#include "../lib/Tree.hpp"
#include "../lib/Parser.hpp"

class Test
{
  private:
    /* Data */
    int sumTest;
    int numTestGlobal;

  public:
    /* Builder */
    Test();

    /* Methodes */
    // Global
    void allTest();

    // Test Tree.hpp
    bool testDefaultBuilderSommet();
    bool testCopyBuilderSommet();
    bool testDefaultBuilderArbreB();
    bool testCopyBuilderArbreB();
    bool testBuilderSommetWithData();
    bool testBuilderArbreBWithData();
    bool testTreeToQueue();
    bool testGetSommetAtIndex();
    bool testAdd();
    bool testDell();
    bool testDepth();
    bool testSize();
    bool testFind();
    bool testSplit();
    bool testJoin();

    // Test Parser.hpp
    bool testCalculFreqChar();
};

#endif