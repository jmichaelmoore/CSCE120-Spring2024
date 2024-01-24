#include <iostream>

using std::cin, std::cout, std::endl;

int main() {
    // declare/define array
    const int SIZE = 5;
    //int ary[SIZE] = {8, 7, 6, 5, 4};
    int ary[SIZE] {8};
    // initialize with braces (modern) - do second
    // initialize with loop (traditional) - do first (includes traversal)
    /*for (unsigned int i=0; i<SIZE; ++i) {
        ary[i] = i+1;
    }*/
    // print values from array (includes traversal)
    for (unsigned int i=0; i<SIZE; ++i) {
        cout << ary[i] << endl;
    }

    cout << endl;
}