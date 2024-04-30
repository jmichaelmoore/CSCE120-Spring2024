#include <iostream>

using std::cin, std::cout, std::endl;

int fib(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    // else recurse
    return fib(n-2) + fib(n - 1);
}

int main() {
    int n = 0;
    while (n >= 0) {
        cout << "enter: ";
        cin >> n;
        cout << "ans: " << fib(n) << endl;
    }
}