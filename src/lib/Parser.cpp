/**
 * Parser.cpp : You can found here all functions implemented for the Parser class.
 * Author : Mickael.
 **/

#include "Parser.hpp"

/**
 * Function : freChar.
 * Argument : nameFile, the name of the read file,
 *              freq, vector with all character frequency.
 *                 freq[i%2] = char, freq[(i%2)+1] = freq of char
 * Description : Read the nameFile and fill the freq vector.
 * */
std::vector<Data> Parser::freqChar(std::string nameFile) const {
    std::ifstream flux(nameFile);
    
    int buffSize = 256; bool seeChar;
    int posCharRead = 0;

    std::vector<Data> tabFreq;
    tabFreq.reserve(buffSize);
    char read;

    if(flux) {
        while(flux.get(read)) { // Read the file
            seeChar = false;
            for(int i=0; i<int(tabFreq.size()); ++i) {
                if(read == tabFreq[i].car) {  // Char found, add freq
                    tabFreq[i].freq++;
                    seeChar = true;
                }
            }
            if(!seeChar) { // Char not found, add char
                Data newData; newData.freq = 1; newData.car = read;
                tabFreq.push_back(newData);
                posCharRead++;
            }
        }
        flux.close();
    }
    else {
        std::cout << "ERROR : can't open '" << nameFile << "'\n";
    }

    Data newData; newData.freq = 0; newData.car = '\0';
    for(int i=posCharRead; i < buffSize; ++i) {
        tabFreq[i] = newData;
    }

    return tabFreq;
}

ArbreB Parser::creatHuffmanTree(std::vector<Data> tabFreq) const {
    // Trie.
    int size = 0;
    for(int i=0; i<int(tabFreq.size()); ++i) {
        for(int j=i+1; j<int(tabFreq.size()); ++j)
        if(tabFreq[i].freq != 0) {
            if(tabFreq[i].freq >= tabFreq[j].freq) {
                Data tmp = tabFreq[i];
                tabFreq[i] = tabFreq[j];
                tabFreq[j] = tmp;
            }
        }
        size++;
    }

    // Create forest.
    std::vector<ArbreB> forest;
    forest.reserve(size);
    for(Data newData : tabFreq) {
        forest.push_back(ArbreB(newData));
    }

    // Merge all tree in one.
    if(size%2) {
        forest[size-2]+=forest[size-1];
    }
    int gap = 1;
    while(gap <= size/2) {
        for(int i=0; i<size-gap; i+=gap) {
            forest[i]+=forest[i+gap];
        }
        gap*=2;
    }

    // Return the final tree.
    return forest[0];
}

std::string Parser::readHuffmanTreeRec(Sommet* node) const{
    if(node->isLeaf()) {
        std::string res(1, node->getData().car);
        return res;
    }
    else {
        std::string res;
        if(node->getLeft()) {
            std::cout << "0";
            return res + readHuffmanTreeRec(node->getLeft());
        }
        if(node->getRight()) {
            std::cout << "1";
            return res + readHuffmanTreeRec(node->getLeft());
        }
    }

    return "\0";
}

std::string Parser::readHuffmanTree(ArbreB huffmanTree) const {
    return readHuffmanTreeRec(huffmanTree.getRoot());
    
}