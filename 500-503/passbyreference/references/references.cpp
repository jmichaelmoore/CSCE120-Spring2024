#include <iostream>

using std::cout, std::endl;

int main() {
    int i = 100;
    // create a reference k to i
    cout << "original values" << endl;
    cout << "i: " << i << endl;
    cout << "k: " << k << endl;

    // modify i
    i *= 2;
    cout << "values after modifying i" << endl;
    cout << "i: " << i << endl;
    cout << "k: " << k << endl;

    // modify k
    k += 5;
    cout << "values after modifying k" << endl;
    cout << "i: " << i << endl;
    cout << "k: " << k << endl;
}