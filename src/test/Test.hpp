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
        bool testBuilderSommetWithParamFailed();
        bool testBuilderSommetWithNumCarAndCar();
        bool testBuilderSommetWithNum();
        bool testBuilderArbreBWithParam();
        bool testTreeToQueue();
        bool testGetSommetAtIndex();
        bool testAdd();
        bool testDepth();
        bool testSize();
        bool testDellNodeAtIndex();

        // Test Parser.hpp
        bool testCalculFreqChar();
};

#endif