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
    ll_1.insertAfter(4, 3);
    printTest("ll_1: insert 4 after 3",ll_1);
    ll_1.insertAfter(2, 9);
    printTest("ll_1: insert 2 after 9",ll_1);
    ll_1.insertBefore(5, 7);
    printTest("ll_1: insert 5 before 7", ll_1);
    ll_1.insertBefore(6, 9);
    printTest("ll_1: insert 6 before 9",ll_1);
    ll_1.printReverse();
 
}