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
            if(posCharRead == buffSize) {
                buffSize += buffSize/2;
                tabFreq.resize(buffSize); // Too many charactere, need to resize
            }
            posCharRead++;

            for(int i=0; i<int(tabFreq.size()); ++i) {
                if(read == tabFreq[i].car) {  // Char found, add freq
                    tabFreq[i].freq++;
                    seeChar = true;
                }
            }
            if(!seeChar) { // Char not found, add char
                Data newData; newData.freq = 1; newData.car = read;
                tabFreq.push_back(newData);
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

ArbreB Parser::creatHuffmanTree(std::vector<Data> tabFreq) {
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

    // std::cout << size << std::endl;
    // for(int i=0; i<int(tabFreq.size()); ++i) {
    //     std::cout << tabFreq[i].car << ", " << tabFreq[i].freq << std::endl;
    // }

    std::vector<ArbreB> forest;
    forest.reserve(size);
    for(int i=0; i<size; ++i) { // Init the tree vector
        ArbreB newtree(tabFreq[i]);
        forest.push_back(newtree);
    }

    int min, min2;
    int posMin, posMin2;
    bool tabSee[size];
    for(int i=0; i<size; ++i) {
        tabSee[i] = false;
    }

    while(int(forest.size()) > 2) {

        // Found the min
        min = forest[0].getRoot()->getData().freq;
        for(int i=1; i<int(forest.size()); ++i) {
            if(forest[i].getRoot()->getData().freq <= min && tabSee[i]) {
                min = forest[i].getRoot()->getData().freq;
                posMin = i;
            }
        }

        // Found the min2
        min2 = forest[0].getRoot()->getData().freq;
        for(int i=1; i<int(forest.size()); ++i) {
            if(forest[i].getRoot()->getData().freq <= min2 && forest[i].getRoot()->getData().freq != min && tabSee[i]) {
                min2 = forest[i].getRoot()->getData().freq;
                posMin2 = i;
            }
        }

        // Create new tree
        // forest[posMin] += forest[posMin2];
    }

    return forest[0];
}