#include <iostream>
#include "LLstr.h"

using std::cout, std::endl;

void printTest(std::string label, const LLstr& l) {
    cout << label << endl;
    cout << '>';
    l.print();
    cout << '<' << endl;
    cout << '>';
    //l.printReverse();
    cout << '<' << endl << endl;
}

int main() {
    LLstr s1;
    printTest("s1: construct", s1);
    s1.insertFront('a');
    s1.insertBack('c');
    printTest("s1: add to front and back", s1);
    LLstr s2("hello");
    printTest("s2: construct from c-string", s2);
    s2.insertFront('@');
    s2.insertBack('&');
    printTest("s2: add to front and back", s2);
    std::string temps  = "World";
    LLstr s3(temps);
    printTest("s3: construct from std::string", s3);
    s3.insertBack('#');
    s3.insertFront('$');
    printTest("s3: add to front and back",s3);
}