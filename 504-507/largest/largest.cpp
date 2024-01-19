#include <iostream>

using std::cout, std::cin, std::endl;

int main() {
    int largest = 0;
    cin >> largest;
    for (unsigned int i=0; i<2; ++i) {
        int num = 0;
        cin >> num;
        if (num > largest) {
            largest = num;
        }
    }
    cout << "largest is " << largest << endl;
}