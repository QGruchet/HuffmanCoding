#include "../lib/Tree.hpp"
#include "../lib/Writer.hpp"
#include "../test/Test.hpp"

int main(void) {
    Test test;
    test.allTest();

    Writer writer("src/txtQt/textToCode.txt");
    writer.writeTextNoEncoding("Ceci est un texte");

    return 0;
}
