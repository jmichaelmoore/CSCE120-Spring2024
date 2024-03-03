#include <iostream>

using std::cout, std::endl;

int main() {
    // declare cstring with '*' called str with 3 elements
    char* str = new char[3];

    str[0] = 'H';
    str[1] = 'i';
    str[2] = '\0';

    // count characters
    unsigned int cnt = 0;
    // set up pointer called iter to move through string and not modify str
    char* iter = str;

    // iterate through string using iter and count as we go
    while (*iter != '\0') {
        cnt++;
        iter++; // iter = iter + 1 - pointer math magic
    }

    cout << "cnt: " << cnt << endl;
    delete[] str;
}