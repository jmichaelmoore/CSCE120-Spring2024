#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>

class DynamicIntArray {
    int* ary;
    size_t size_;
    size_t capacity_;
    void increaseCapacity(size_t capacity = 0);
    void build_copy(const DynamicIntArray& src);

public:
    // constructors
    DynamicIntArray() : ary(nullptr), size_(0), capacity_(0) {}
    DynamicIntArray(size_t size, int val = 0);
    DynamicIntArray(const DynamicIntArray& src);
    ~DynamicIntArray();
    DynamicIntArray& operator=(const DynamicIntArray& src);

    // capacity methods
    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }
    bool empty() const { return size_ == 0; }
    const int& at(size_t index) const;
    int& at(size_t index);
    const int& operator[](size_t index) const { return ary[index]; }
    int& operator[](size_t index) { return ary[index]; }
    void push_back(int val);
};

#endif