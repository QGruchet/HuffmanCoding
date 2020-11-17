#ifndef Test_HPP
#define Test_HPP

#include "../lib/Tree.hpp"
#include "../lib/Parser.hpp"
#include "../lib/Writer.hpp"

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
    // Sommet
    bool testDefaultConstructorNode();
    bool testCopyConstructorNode();
    bool testParamConstructorNode();
    bool TestEqualsNode();
    bool testAssignNode();
    bool testEqualsNode();
    bool testDepth();
    bool testSize();   
    
    // ArbreB
    bool testDefaultConstructorTree();
	bool testParamConstructorTree();
	bool testAssignTree();
	bool TestEqualsTree();
	bool testAdd();
    bool testDell();
    bool testFind();
    bool testGetNodeAtIndex();
    bool testJoin();
    bool testSplit();

    // Writer
    void testWriteTreeInQt();
    void testWriteAllTest();
    
    // Parser
    bool testCalculFreqChar();

    // Getters
    int getSumTest() const;
    int getNumTestGlobal() const;

    // Tools
    std::string inRed(std::string msg);
    std::string inGreen(std::string msg);
};

#endif
