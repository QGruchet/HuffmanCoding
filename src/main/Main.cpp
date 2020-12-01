#include "../lib/Tree.hpp"
#include "../lib/Writer.hpp"
#include "../test/Test.hpp"

int main(void) {
    Test test;
    test.allTest();

    Writer writer("src/txtQt/textToCode.txt");
    writer.writeTextNoEncoding("Ceci est un message, si tu ne le lit pas je te marave");

    return 0;
}
