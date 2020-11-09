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
        bool testBuilderSommetWithParam() const;
        bool testBuilderSommetWithParamFailed() const;
        bool testBuilderArbreBWithParam() const;

        // Test Parser.hpp
        bool testCalculFreqChar() const;
};

#endif