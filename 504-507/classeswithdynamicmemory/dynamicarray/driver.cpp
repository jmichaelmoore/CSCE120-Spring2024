#include <iostream>
#include "DynamicIntArray.h"

using namespace std;

void printArray(const DynamicIntArray& ary);

int main() {
  // declare/define instance
  DynamicIntArray a;
  printArray(a);

  DynamicIntArray b(3,4);
  printArray(b);

  DynamicIntArray c(5);
  printArray(c);

  c.at(2) = 9;

  c[0] = 1;

  printArray(c);

  b.push_back(8);

  printArray(b);

  a.push_back(6);
  printArray(a);
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