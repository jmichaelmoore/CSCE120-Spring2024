#include <iostream>
#include <sstream>

using std::cin, std::cout, std::endl, std::string;

int main() {
    // demo pre-decrement and post-decrement
    int i = 3;
    int j = 7;
    int p = 2*i++;
    int w = 2*++j;
    cout << "p: " << p << endl;
    cout << "w: " << w << endl;
}