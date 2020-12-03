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

bool stayOneTree(std::vector<ArbreB> forest) {
    int _stayOneTree = 0;
    for(int i=0; i<int(forest.size()); ++i) {
        if(forest[i].getRoot()->getData().freq != -1) {
            _stayOneTree++;
        }
    }
    return (_stayOneTree == 1);
}

ArbreB Parser::creatHuffmanTree(std::vector<Data> tabFreq) const {
    // Sort.
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

    int posMin, posMin2;

    // Merge all tree in one.
    while(!stayOneTree(forest)) {
        int min = INT32_MAX; // Init min with the max value for int;
        int min2 = INT32_MAX;

        //
        for(int i=0; i<int(forest.size()); ++i) {
            if(forest[i].getRoot()->getData().freq != -1
            && forest[i].getRoot()->getData().freq <= min) {
                min = forest[i].getRoot()->getData().freq;
                posMin = i;
            }
        }
        for(int i=0; i<int(forest.size()); ++i) {
            if(forest[i].getRoot()->getData().freq != -1
            && forest[i].getRoot()->getData().freq <= min2
            && !(*forest[i].getRoot() == *forest[posMin].getRoot())) {
                min2 = forest[i].getRoot()->getData().freq;
                posMin2 = i;
            }
        }

        forest[posMin2] += forest[posMin];
        Data newData; newData.freq = -1; newData.car = '\0';
        *forest[posMin].getRoot() = newData;
    }

    // Return the final tree.
    for(int i=0; i<int(forest.size()); ++i) {
        if(forest[i].getRoot()->getData().freq != -1) {
            return forest[i];
        }
    }

    ArbreB tmp;
    return tmp;
}

void Parser::readHuffmanTree(Sommet* node, std::string str, std::stack<std::string>* stack) const{
    if(node->isLeaf()) {
        stack->push(str + node->getData().car);
    }
    else {
        if(node->getLeft()) {
            str += "0";
            readHuffmanTree(node->getLeft(), str, stack);
            str.pop_back();
        }
        if(node->getRight()) {
            str += "1";
            readHuffmanTree(node->getRight(), str, stack);
            str.pop_back();
        }
    }
}