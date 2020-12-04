#include "../lib/Tree.hpp"
#include "../lib/Writer.hpp"
#include "../test/Test.hpp"

int main(void) {
    // Test test;
    // test.allTest();

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
        convert += stack.top();
        std::cout << stack.top() << std::endl;
        tmp.push(stack.top());
        stack.pop();
    }

    while(!tmp.empty()) {
        stack.push(tmp.top());
        tmp.pop();
    }
    std::cout << "Convert : " << convert << std::endl;
    
    // for(int i=0; i<256; ++i) {
    //     if(tabCode[i] != "\0") {
    //         std::cout << tabCode[i] << std::endl;
    //     }
    // }

    return 0;
}
