// header guards
#ifndef ARRAYFUNCTIONS_H
#define ARRAYFUNCTIONS_H

const unsigned int CAPACITY = 100; // make largest size we will ever need

// functions to add
// loadRandom
// insert
// remove at index
// remove first of
// getMax // linear search
// getMin 
// count val
// print

void makeAry(int*& , unsigned int);

void print(const int ary[], unsigned int size);
void loadRandom(int ary[], int size);
void insert(int val, unsigned int index, 
          int ary[], unsigned int size);
void removeAtIndex(unsigned int index, 
          int ary[], unsigned int size);
void removeFirstOf(int val, 
          int ary[], unsigned int size);
int getMax(const int ary[], unsigned int size);
int getMin(const int ary[], unsigned int size);
unsigned int countVal(int val, const int ary[], unsigned int size);

#endif