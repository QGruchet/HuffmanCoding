/**
 * Parser.hpp : You can found here all functions implemented for the Parser class.
 * Author : Mickael.
 **/

#ifndef Parser_HPP
#define Parser_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Parser
{
    public:
        /* Methodes */
        void freqChar(std::string nameFile, std::vector<int> freq) const;
};

#endif