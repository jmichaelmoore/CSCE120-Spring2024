#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include<iostream>

class DynamicIntArray {
    int* ary;
    size_t size_;
    size_t capacity_;
    void increaseCapacity();
public:
    DynamicIntArray() : ary(nullptr), size_(0), capacity_(0) {}
    DynamicIntArray(size_t size, int val);
    size_t size() { return size_; }
    size_t capacity() { return capacity_; }
    size_t empty() { return size_ == 0; }
};

#endif