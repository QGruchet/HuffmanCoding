#ifndef Test_HPP
#define Test_HPP

#include "../lib/Tree.hpp"
#include "../lib/Parser.hpp"

class Test
{
    public:
        /* Methodes */
        // Global
        void allTest() const;

        // Test Tree.hpp
        bool testDefaultBuilderSommet() const;
        bool testCopyBuilderSommet() const;
        bool testDefaultBuilderArbreB() const;
        bool testCopyBuilderArbreB() const;
        bool testBuilderSommetWithParamFailed() const;
        bool testBuilderSommetWithNumCarAndCar() const;
        bool testBuilderSommetWithNum() const;
        bool testBuilderArbreBWithParam() const;
        bool testCopyArbreB() const;
        bool testTreeToQueue() const;
        bool testGetSommetAtIndex() const;
        bool testAddNode() const;
        bool testAddNode2() const;
        bool testDepth() const;
        bool testSize() const;
        bool testDellNodeAtIndex() const;

        // Test Parser.hpp
        bool testCalculFreqChar() const;
};

#endif