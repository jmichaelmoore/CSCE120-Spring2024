#include <iostream>
#include "arrayFunctions.h"

using std::cin, std::cout, std::endl;

void loadRandom(int ary[], unsigned int size) {
  for (unsigned int i = 0; i < size; ++i) {
    ary[i] = rand()%100;
  }
  // We'll do together
}

void insert(int val, unsigned int index, 
          int ary[], unsigned int size) {
  if (size == CAPACITY) {
    return;
  }
  if (index > size) {
    index = size;
  }
  for (unsigned int i=size; i > index; --i) {
    ary[i] = ary[i-1];
  }
  ary[index] = val;
  // We'll do together
}

void removeAtIndex(unsigned int index, 
          int ary[], unsigned int size) {

}

void removeFirstOf(int val, 
          int ary[], unsigned int size) {

}

int getMax(const int ary[], unsigned int size) {
  // We'll do together
  return 0;
}

int getMin(const int ary[], unsigned int size) {
  // do on your own
  return 0;
}

unsigned int countVal(int val, const int ary[], unsigned int size) {
  // do on your own
  return 0;
}

// print including empty
void print(const int ary[], unsigned int size) {
  // We'll do together
  for (unsigned int i=0; i<size; ++i) {
    cout << ary[i] << " ";
    if ((i+1)%10==0) cout << endl;
  }
  if (size==0) {
    cout << "Empty array";
  }
  cout << endl;
}
