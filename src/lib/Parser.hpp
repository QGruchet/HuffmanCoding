/**
 * Parser.hpp : You can found here the Parser class.
 * Author : Mickael.
 **/

#ifndef Parser_HPP
#define Parser_HPP

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#include "Tree.hpp"

class Parser
{
    public:
        /* Methodes */
        std::vector<struct Data> freqChar(std::string) const;
        ArbreB creatHuffmanTree(std::vector<Data>) const;
        std::string readHuffmanTreeRec(Sommet*) const;
        std::string readHuffmanTree(ArbreB) const;
};

#endif