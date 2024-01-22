#include <iostream>

using std::cout, std::cin, std::endl;

int main() {
  double sum = 0;
  double num = 0;
  unsigned int count = 0;
  do {
    cin >> num;
    if (num >= 0) { // ignores any negative number
      sum += num;
      count++;
    }
  } while (num != -1); // only exits with -1

  cout << "average: " << sum/count << endl;
  return 0; // this is optional in main function, I usually don't include it
}