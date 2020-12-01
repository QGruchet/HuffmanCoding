#include "../lib/Tree.hpp"
#include "../lib/Writer.hpp"
#include "../test/Test.hpp"

int main(void) {
    // Test test;
    // test.allTest();

    Writer writer("src/txtQt/text.txt");
    writer.writeTextNoEncoding("Ceeciiiz");
    Writer writer2("src/txtQt/code.txt");
    writer2.writeTextCoding();
    
    return 0;
}
