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
void Parser::freqChar(std::string nameFile, std::vector<int> freq) const {
    std::ifstream flux(nameFile);
    char read;
    int buffChar = 256, buffSize = 2*buffChar, oldBuffChar = 0;

    if(flux) { // If file is correctly opened
        freq.reserve(buffSize);
        for(int i=0; i<buffSize; ++i) { // Init freq with 0
            freq[i] = 0;
        }
        
        int posCharRead = 0;
        while(flux.get(read)) { // Read the file
            if(posCharRead >= buffChar) {
                oldBuffChar = buffChar;
                buffChar += buffChar/2;
                freq.resize(buffSize); // Too many charactere, need to resize
                for(int i=oldBuffChar; i<buffSize; ++i) {
                    freq[i] = 0;
                }
            }
            flux.get(read);
            posCharRead++;
            for(int i=0; i<buffSize; i+=2) { // char found, add freq
                if(read == freq[i]) {
                    freq[i+1] += 1;
                }
            }
        }
        flux.close();
    }
    else {
        std::cout << "ERROR : open file failed." << std::endl;
    }
}