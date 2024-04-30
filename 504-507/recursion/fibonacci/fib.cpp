#include <iostream>

using std::cin, std::cout, std::endl;

int fib(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fib(n-1) + fib(n-2);
}

int main() {
    int n = 0;
    while (n >= 0) {
        cout << "enter: ";
        cin >> n;
        cout << "ans: " << fib(n) << endl;
    }
}