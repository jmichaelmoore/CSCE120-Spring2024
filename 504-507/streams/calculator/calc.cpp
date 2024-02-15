#include <iostream>
#include <sstream>

using std::cin, std::cout, std::endl, std::string;

int main() {
    string line;
    cout << "Enter equation in one line: " << endl;
    // use getline, explain polymorphism and inheritance
    std::getline(cin, line);
    double result = 0;
    double firstNum = 0;
    double secondNum = 0;
    char op = ' ';
    // set up string steram
    // determine what to do based on the op
    cout << "result: " << result;
}