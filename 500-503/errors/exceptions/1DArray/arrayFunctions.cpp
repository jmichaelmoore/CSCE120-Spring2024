#include <iostream>
#include "arrayFunctions.h"
#include <stdexcept>

using std::cin, std::cout, std::endl;

void loadRandom(int ary[], unsigned int size) {
  // assumes size is less than capacity
  if (size > CAPACITY) {
    throw std::out_of_range("size cannot be greater than the capacity.");
  }
  for (unsigned int i=0; i<size; ++i) {
    ary[i] = rand()%100;
  }
  // We'll do together
}

void insert(int val, unsigned int index, 
          int ary[], unsigned int size) {
  // We'll do together
  // if (index == CAPACITY) {
  //   return; // do nothing 
  // }
  if (index >= CAPACITY) {
    throw std::out_of_range("cannot insert at index greater than capacity");
  }
  if (index > size) { // move index to end of list
    index = size;
  }
  for (unsigned int i = size; i > index; --i) {
    ary[i] = ary[i-1];
  }
  ary[index] = val;
}

void removeAtIndex(unsigned int index, 
          int ary[], unsigned int size) {
  if (index >= size) {
    throw std::out_of_range("index outside the boinds of the array");
  }
}

void removeFirstOf(int val, 
          int ary[], unsigned int size) {

}

int getMax(const int ary[], unsigned int size) {
  // We'll do together
  int maxVal = ary[0];
  for (unsigned int i=1; i<size; ++i) {
    if (ary[i] > maxVal) {
      maxVal = ary[i];
    }
  }
  return maxVal;
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
  if (size == 0) {
    cout << "Empty Array";
  }
  for (unsigned int i=0; i<size; ++i) {
    cout << ary[i] << " ";
    if ((i+1)%10 == 0) {
      cout << endl;
    }
  }
  cout << endl;
  // We'll do together
}
