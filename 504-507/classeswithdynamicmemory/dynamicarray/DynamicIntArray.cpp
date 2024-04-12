#include "DynamicIntArray.h"

DynamicIntArray::DynamicIntArray(size_t size, int val) 
        : ary(nullptr), size_(0), capacity_(0) {
    increaseCapacity(size);
    for (size_t i=0; i<size; ++i) {
        this->ary[i] = val;
    }
    this->size_ = size;
}

void DynamicIntArray::increaseCapacity(size_t capacity) {
    size_t newCapacity = 0;
    if (capacity == 0) {
        if (this->capacity_ == 0) {
            newCapacity = 1;
        }
        else 
            newCapacity = this->capacity_*2;
    }
    else {
        if (capacity <= this->capacity_)
            return;
        else
            newCapacity = capacity;
    }

    int* newAry = new int[newCapacity];

    // copy
    for (size_t i=0; i<capacity_; ++i) {
        newAry[i] = ary[i];
    }

    // delete
    delete [] ary;

    // fix
    ary = newAry;
    capacity_ = newCapacity;
}

const int& DynamicIntArray::at(size_t index) const {
    if (index >= this->size_) {
        throw std::out_of_range("out of range");
    }
    return this->ary[index];
}

int& DynamicIntArray::at(size_t index) {
    if (index >= this->size_) {
        throw std::out_of_range("out of range");
    }
    return this->ary[index];
}

void DynamicIntArray::push_back(int val) {
    if (this->size_ == this->capacity_) {
        increaseCapacity();
    }
    this->ary[size_] = val;
    size_++;
}

DynamicIntArray::~DynamicIntArray() {
    delete [] ary;
    size_ = 0;
    capacity_ = 0;
    ary = nullptr;
}

DynamicIntArray::DynamicIntArray(const DynamicIntArray& src) 
        : ary(nullptr), size_(src.size_), capacity_(src.capacity_) {
    build_copy(src);
}

DynamicIntArray& DynamicIntArray::operator=(const DynamicIntArray& src) {
    if (this != &src) {
        delete [] this->ary;
        this->size_ = src.size_;
        this->capacity_ = src.capacity_;
        build_copy(src);
    }
    return *this;
}

void DynamicIntArray::build_copy(const DynamicIntArray& src) {
    this->ary = new int[this->capacity_];
    for (size_t i=0; i<this->size_; ++i) {
        this->ary[i] = src.ary[i];
    }
}