#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>

class DynamicIntArray {
    int* ary;
    size_t size_;
    size_t capacity_;
    void increaseCapacity(size_t newCapacity = 0);

public:
    // constructors
    DynamicIntArray() : ary(nullptr), size_(0), capacity_(0) {}
    DynamicIntArray(size_t size, int val);

    // capacity methods
    size_t size() { return size_; }
    size_t capacity() { return capacity_; }
    bool empty() { return size_ == 0; }
};

#endif