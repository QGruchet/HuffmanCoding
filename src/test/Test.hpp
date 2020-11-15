#ifndef Test_HPP
#define Test_HPP

#include "../lib/Tree.hpp"
#include "../lib/Parser.hpp"

class Test
{
  private:
    /* Data */
    int sumTest;
    int numTestSucced;

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
    bool testDepth();
    bool testSize();
    bool testDell();

    // Test Parser.hpp
    bool testCalculFreqChar();
};

#endif