#include "functions.h"

int digitsum(int num) {
    int sum = 0;
    while (num != 0) {
        int digit = num%10;
        sum += digit; // sum = sum + digit;
        num /= 10; // num = num / 10;
    }
    return sum;
}