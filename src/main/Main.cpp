#include "../lib/Tree.hpp"
#include "../lib/Writer.hpp"
#include "../test/Test.hpp"

#define DEBUG false

int main(void) {
    if(DEBUG) {
        Test test;
        test.allTest();

        Writer writer("src/txtQt/text.txt");
        writer.textToCode("Bonjour");
        Parser parser;
        ArbreB huffmanTree = parser.creatHuffmanTree(parser.freqChar("src/txtQt/text.txt"));
        huffmanTree.getRoot()->printBeautifulTree(0);
        std::string str = "\0";
        std::stack<std::string> stack;
        parser.readHuffmanTree(huffmanTree.getRoot(), str, &stack);

        std::stack<std::string> tmp;
        std::string convert = "\0";
        while(!stack.empty()) {
            std::cout << stack.top() << std::endl;
            tmp.push(stack.top());
            stack.pop();
        }

        while(!tmp.empty()) {
            stack.push(tmp.top());
            tmp.pop();
        }
        std::cout << "Convert : " << convert << std::endl;
    }

    return 0;
}
