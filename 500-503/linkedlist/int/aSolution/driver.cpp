#include <iostream>
#include "LLint.h"

using std::cin, std::cout, std::endl;

void printTest(std::string label, const LLint& l) {
    cout << label << endl;
    l.print();
    cout << endl;
    cout << endl << endl;
}

int main() {
    LLint ll_1;
    printTest("ll_1: constructor", ll_1);
    ll_1.insertBack(8);
    printTest("ll_1: insertBack", ll_1);
    ll_1.insertFront(3);
    printTest("ll_1: insertFront", ll_1);
    ll_1.insertBack(7);
    printTest("ll_1: insertBack", ll_1);
}