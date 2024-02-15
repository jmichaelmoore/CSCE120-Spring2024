#include <iostream>
#include <sstream>

using std::cin, std::cout, std::endl, std::string;

string makeResult(double a, double b, char op, double result) {
    // create output string stream
    // build string with the equation and answer
    // extract string from string stream
    return "";
}

int main() {
    string line;
    cout << "Enter equation in one line: " << endl;
    // use getline, explain polymorphism and inheritance
    std::getline(cin, line);
    double result = 0;
    double firstNum = 0;
    double secondNum = 0;
    char op = ' ';
    // set up input string steram
    // determine what to do based on the op
    cout << "result: " << result << endl;
    string output = makeResult(firstNum, secondNum, op, result);
    cout << output << endl;
}