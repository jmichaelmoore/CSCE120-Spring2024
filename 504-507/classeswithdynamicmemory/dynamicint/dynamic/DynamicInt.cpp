#include "DynamicInt.h"

DynamicInt& DynamicInt::operator=(int val) { 
  *(this->val) = val; 
  return *this;
}

std::ostream& operator<<(std::ostream& os, const DynamicInt& src) {
  os << src.get();
  return os;
}

