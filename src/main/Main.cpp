#include "../lib/Tree.hpp"
#include "../lib/Writer.hpp"
#include "../test/Test.hpp"

#define DEBUG1 false    // Debug for test
#define DEBUG2 true     // Debug for encoding
#define DEBUG3 true     // Debug for decoding

int main(void) {
    if(DEBUG1) {
        Test test;
        test.allTest();
    }
    if(DEBUG2) {
        std::cout << "################## Test encoding ##############" << std::endl;
        std::string text = "bonjour";
        Writer writer("src/txtQt/text.txt");
        writer.textToCode(text);

        Parser parser;
        ArbreB huffmanTree = parser.creatHuffmanTree(parser.freqChar("src/txtQt/text.txt"));
        huffmanTree.getRoot()->printBeautifulTree(0);

        std::string str = "\0";
        std::stack<std::string> stack;
        parser.readHuffmanTree(huffmanTree.getRoot(), str, &stack);
        
        std::string convert = "\0";
        std::map<char, std::string> map;
        while(!stack.empty()) {
            std::string tmp;
            tmp = stack.top();
            stack.pop();
            char c = tmp.back();
            tmp.pop_back(); // Erase the car
            // std::cout << c << " : " << tmp << std::endl;
            map[c]=tmp;
        }

        for(char c : text) {
            std::map<char, std::string>::iterator it = map.find(c);
            convert += it->second;
        }

        std::cout << "Text : " << text << ", Convert : " << convert << std::endl;
        std::cout << "###############################################\n" << std::endl;
    }
    if(DEBUG3) {
        std::cout << "################## Test decoding ##############" << std::endl;
        std::string text = "011100100011000011";
        Writer writer("src/txtQt/code.txt");
        writer.textToCode(text);

        Data data1; data1.car = 'b', data1.freq = 1;
        Data data2; data2.car = 'o', data2.freq = 2;
        Data data3; data3.car = 'n', data3.freq = 1;
        Data data4; data4.car = 'j', data4.freq = 1;
        Data data5; data5.car = 'u', data5.freq = 1;
        Data data6; data6.car = 'r', data6.freq = 1;

        std::vector<Data> tabFreq;
        tabFreq.push_back(data1);
        tabFreq.push_back(data2);
        tabFreq.push_back(data3);
        tabFreq.push_back(data4);
        tabFreq.push_back(data5);
        tabFreq.push_back(data6);

        Parser parser;
        ArbreB huffmanTree = parser.creatHuffmanTree(tabFreq);
        huffmanTree.getRoot()->printBeautifulTree(0);

        std::string str = "\0";
        std::stack<std::string> stack;
        parser.readHuffmanTree(huffmanTree.getRoot(), str, &stack);

        std::string convert = "\0";
        std::map<std::string, char> map;
        while(!stack.empty()) {
            std::string tmp;
            tmp = stack.top();
            stack.pop();
            char c = tmp.back();
            tmp.pop_back(); // Erase the car
            // std::cout << c << " : " << tmp << std::endl;
            map[tmp]=c;
        }

        std::string tmp = "\0";
        int positionText = 0;
        while(positionText <= (int)text.size()) {
            std::map<std::string, char>::iterator it;
            it = map.find(tmp);
            if(it != map.end()) {
                // std::cout << it->second << " : " << it->first << std::endl;
                convert += it->second;
                tmp = "\0";
            }
            if(positionText < (int)text.size()) {
                tmp += text.at(positionText);
            }
            positionText++;
            // std::cout << "etape : " << positionText << "tmp = " << tmp << std::endl;
        }

        std::cout << "Text : " << text << ", Convert : " << convert << std::endl;
        std::cout << "###############################################\n" << std::endl;
    }

    return 0;
}
