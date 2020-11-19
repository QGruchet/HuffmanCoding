#include "../lib/Tree.hpp"
#include "../lib/Writer.hpp"
#include "../test/Test.hpp"

int main(void) {
    Test test;
    test.allTest();

    /* ##### writer ##### */
    ArbreB tree(2);
    tree << 4;
    tree << 6;
    tree << 8;
    tree << 10;
    tree << 2;
    tree << 7;
    tree << 4;
    tree << 28;
    tree << 0;
    tree << 4;

    Writer writer("src/txtQT/binary.txt");
    writer.writeBeautifulTreeInFile(tree);

    Writer writer2("src/txtQT/resultTest.txt");
    writer2.writeResultAllTests();

    return 0;
}
