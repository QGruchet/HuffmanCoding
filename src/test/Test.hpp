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
    /* Constructor */
    Test();

    /* Methodes */
    // Global
    void allTest();

    // Test Tree
    bool testDefaultBuilderNode();
    bool testDefaultBuilderTree();
    bool testGetNodeAtIndex();
    bool testAdd();
    bool testDell();
    bool testDepth();
    bool testSize();
    bool testFind();
    bool testJoin();
    bool testSplit();
    bool testCopy();
    bool testAssignTree();
    bool TestEqualsTree();

    // Test Parser
    bool testCalculFreqChar();
};

#endif
