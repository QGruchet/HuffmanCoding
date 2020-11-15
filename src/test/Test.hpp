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

    // Test Tree.hpp
    bool testDefaultConstructorSommet();
    bool testConstructorSommetWithData();
    bool testDefaultConstructorArbreB();
    bool testConstructorArbreBWithData();
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