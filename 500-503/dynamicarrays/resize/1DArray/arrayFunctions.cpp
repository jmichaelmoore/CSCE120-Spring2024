#include <iostream>
#include "arrayFunctions.h"

using std::cin, std::cout, std::endl;

using std::out_of_range;

// always throw an out_of_range exception for any invalid index

void resize(int*& ary, unsigned int& capacity) {
  unsigned int newCapacity = capacity*2;
  if (newCapacity == 0) {
    newCapacity = 1;
  }

  // create temp
  int* newAry = new int[newCapacity];
  for (unsigned int i=0; i<newCapacity; ++i) {
    newAry[i] = 0;
  }

  
  // copy
  for (unsigned int i=0; i<capacity; ++i) {
    newAry[i] = ary[i];
  }

  // delete old memory
  delete [] ary;

  ary = newAry;
  capacity = newCapacity;

  newAry = nullptr;
}

void makeAry(int*& ary, unsigned int size) {
  delete [] ary;
  ary = new int[size];
}

void releaseArray(int*& ary, unsigned int& size, unsigned int& capacity) {
  delete [] ary;
  ary = nullptr;
  size = 0;
  capacity = 0;
}


void loadRandom(int*& ary, unsigned int size, unsigned int& capacity) {
  for (unsigned int i=0; i<size; ++i) {
    if (i >= capacity) {
      resize(ary, capacity);
    }
    ary[i] = rand()%1000;
  }
}

void insert(int val, unsigned int index, 
          int*& ary, unsigned int& size, unsigned int& capacity) {
  if (size == capacity) { // is there space
    resize(ary, capacity);
  }
  if (index > size) { // if index too big, slide to add to end
    index = size;
  }

  for (unsigned int i = 0; i < size-index; ++i) {
    // slide number
    ary[size-i] = ary[size-i-1];
  }

  ary[index] = val;
  ++size;
}

void removeAtIndex(unsigned int index, 
          int ary[], unsigned int size) {
  // do on your own
}

void removeFirstOf(int val, 
          int ary[], unsigned int size) {
  // do on your own
}

int getMax(const int ary[], unsigned int size) {
  // do on your own
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
  if (size == 0) {
    cout << "Empty list" << endl;
  } else {
    for (unsigned int i=0; i<size; ++i) {
      cout << ary[i] << endl;
    }
  }
}
