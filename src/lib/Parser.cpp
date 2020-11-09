#include "Parser.hpp"

void Parser::freqChar(std::string nameFile, std::vector<int> freq) const {
    std::ifstream flux(nameFile);
    char read;
    int buffChar = 256, oldBuffChar = 0;

    if(flux) {
        freq.reserve(buffChar*buffChar);
        for(int i=0; i<buffChar*buffChar; ++i) {
            freq[i] = 0;
        }
        
        int posCharRead = 0;
        while(flux.get(read)) {
            if(posCharRead >= buffChar) {
                oldBuffChar = buffChar;
                buffChar += buffChar/2;
                freq.resize(buffChar*buffChar);
                for(int i=oldBuffChar; i<buffChar*buffChar; ++i) {
                    freq[i] = 0;
                }
            }
            flux.get(read);
            posCharRead++;
            for(int i=0; i<buffChar*buffChar; i+=2) {
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