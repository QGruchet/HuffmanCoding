/**
 * Test.hpp : You can found here the Test class.
 * Author : Mickael.
 **/

#ifndef Test_HPP
#define Test_HPP

#include "../lib/Tree.hpp"

class Test
{
  private:
    /* Data */
    int sumTest;        // Number tests is passed.
    int numTestGlobal;  // Number test in global
    bool inColor;       // Print test in color

  public:
    /* Constructor */
    Test();
    Test(bool withColor);

    /* Methodes */
    // Global
    void allTest();

    // Test Tree
    // Sommet
    std::string testDefaultConstructorNode();
    std::string testCopyConstructorNode();
    std::string testParamConstructorNode();
    std::string testAssignNode();
    std::string testEqualsNode();
    std::string testDepth();
    std::string testSize();   
    
    // ArbreB
    std::string testDefaultConstructorTree();
  	std::string testParamConstructorTree();
  	std::string testAssignTree();
  	std::string TestEqualsTree();
  	std::string testAdd();
    std::string testDell();
    std::string testFind();
    std::string testGetNodeAtIndex();
    std::string testJoin();
    std::string testSplit();

    // Getters
    int getSumTest() const;
    int getNumTestGlobal() const;
};

#endif
