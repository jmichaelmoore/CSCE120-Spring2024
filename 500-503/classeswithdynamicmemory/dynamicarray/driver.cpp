#include <iostream>
#include "DynamicIntArray.h"

using namespace std;

void printArray(const DynamicIntArray& ary);

int main() {
  // declare/define instance
  DynamicIntArray a;
  printArray(a);

  DynamicIntArray b(3, 7);
  printArray(b);

  DynamicIntArray c(5);
  printArray(c);

  c.at(2) = 2;
  c[0] = 9;

  printArray(c);

  b.push_back(1);

  printArray(b);
}

void printArray(const DynamicIntArray& ary) {
  if (ary.empty()) {
    cout << "Empty!" << endl;
  }
  else {
    for (size_t i=0; i<ary.size(); ++i) {
      cout << ary.at(i) << endl;
    }
  }
}