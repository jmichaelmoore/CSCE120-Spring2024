#include <iostream>
#include "DynamicIntArray.h"

using namespace std;

void printArray(string label, const DynamicIntArray& ary);

int main() {
  // declare/define instance
  DynamicIntArray a;
  printArray("a", a);

  DynamicIntArray b(3,4);
  printArray("b", b);

  DynamicIntArray c(5);
  printArray("c", c);

  c.at(2) = 9;

  c[0] = 1;

  printArray("c", c);

  b.push_back(8);

  printArray("b", b);

  a.push_back(6);
  printArray("a", a);

  DynamicIntArray d = b;
  printArray("d", d);

  a = c;
  printArray("a", a);

  a.at(a.size()-1) = 11;
  printArray("a", a);
  printArray("c", c);
}

void printArray(string label, const DynamicIntArray& ary) {
  cout << endl << label << endl;
  if (ary.empty()) {
    cout << "Empty!" << endl;
  }
  else {
    for (size_t i=0; i<ary.size(); ++i) {
      cout << ary.at(i) << endl;
    }
  }
}