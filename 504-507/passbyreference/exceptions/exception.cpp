#include <iostream>

using std::cin, std::cout, std::endl;

int main() {
  std::string str;
  size_t index = 0;
  cout << "Enter string: ";
  cin >> str;
  cout << "Enter index: ";
  cin >> index;

  try {
    char l = str.at(index);
    cout << "Letter at index " << index << " is '" << l << "'." << endl;
  }
  catch (std::out_of_range e) {
    cout << e.what() << endl;
  }
}