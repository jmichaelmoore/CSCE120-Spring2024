#include <iostream>

using std::cin, std::cout, std::endl, std::string;

int main() {
  string str;
  size_t index = 0;
  cout << "enter a string: ";
  cin >> str;
  cout << "enter location of letter to get: ";
  cin >> index;
  cout << "the character at index " << index << " is " << str.at(index) << endl;
}