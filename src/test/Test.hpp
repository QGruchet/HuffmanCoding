#ifndef Test_HPP
#define Test_HPP

#include "../lib/Tree.hpp"

class Test
{
    public:
        /* Methodes */
        // Global
        void allTest() const;

        // Test builder
        bool testDefaultBuilderSommet() const;
        bool testCopyBuilderSommet() const;
        bool testDefaultBuilderArbreB() const;
        bool testCopyBuilderArbreB() const;
        bool testBuilderSommetWithParam() const;
        bool testBuilderSommetWithParamFailed() const;
        bool testBuilderArbreBWithParam() const;
};

#endif