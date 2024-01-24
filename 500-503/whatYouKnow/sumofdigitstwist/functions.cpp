#include "functions.h"

int digitsum(int num) {
  bool isPos = num >= 0;
  int sum = 0;
  int prev = num%10;
  num /= 10;
  while (num != 0) {
    int digit = num%10;
    if (prev%2 == 0) { // is even
        sum += digit; // sum = sum + digit;
    }
    else { // is odd
        sum -= digit; // sum = sum - digit;
    }
    
    num /= 10; // num = num / 10;
  }
  if (isPos) {
    return sum;
  }
  else {
    return sum*-1;
  }
}