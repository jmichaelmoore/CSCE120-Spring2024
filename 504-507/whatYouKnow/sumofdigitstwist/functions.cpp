#include "functions.h"

int digitsum(int num) {
    bool isPos = num >= 0;
    int sum = 0;
    int prev = num%10;
    num /= 10;
    while (num != 0) {
        int digit = num%10;
        if (digit%2 == 0) { // is even
            sum += prev; // sum = sum + digit; 
        }
        else { // is odd
            sum -= prev; // sum = sum - digit;
        }
        prev = digit;
        num /= 10; // num = num / 10;
    }
    sum += prev; // add final leftmost digit
    if (isPos) 
        return sum;
    else
        return sum*-1;
}