#include <iostream>

using std::cout, std::cin, std::endl, std::string;

int main() {
    std::string name = "";
    cout << "What is your name?" << endl;
    cin >> name;
    cout << name << ", welcome to CSCE 120!" << endl;
}