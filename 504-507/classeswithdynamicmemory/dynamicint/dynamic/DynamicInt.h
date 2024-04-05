#ifndef DYNAMICINT_H
#define DYNAMICINT_H

#include<iostream>

class DynamicInt{
  int* val;
public:
  DynamicInt() : val(new int(0)) {}
  DynamicInt(int val) : val(new int(val)) {}
  DynamicInt& operator=(int val);
  int get() const { return *val; }
};

std::ostream& operator<<(std::ostream& os, const DynamicInt& src);

#endif