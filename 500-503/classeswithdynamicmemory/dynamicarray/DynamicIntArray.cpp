#include "DynamicIntArray.h"

void DynamicIntArray::increaseCapacity(size_t capacity) {
    size_t newCapacity = 0;
    if (capacity == 0) {
        if (this->capacity_ ==0) 
            newCapacity = 1;
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

    for (size_t i=0; i<this->size_; ++i) {
        newAry[i] = this->ary[i];
    }

    delete [] ary;

    this->ary = newAry;
    this->capacity_ = newCapacity;
    newAry = nullptr;
}

DynamicIntArray::DynamicIntArray(size_t size, int val) 
        : ary(nullptr), size_(0), capacity_(0) {
    if (size == 0) return; // do nothing
    this->increaseCapacity(size);
    this->size_ = size;
    for (size_t i=0; i<this->size_; ++i) {
        this->ary[i] = val;
    }
}

const int& DynamicIntArray::at(size_t index) const {
    if (index >= this->size_) {
        throw std::out_of_range("out of range");
    }
    return ary[index];
}

int& DynamicIntArray::at(size_t index) {
    if (index >= this->size_) {
        throw std::out_of_range("out of range");
    }
    return ary[index];
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

void DynamicIntArray::setup_copy(const DynamicIntArray& src) {
    this->ary = new int[this->capacity_];
    for (size_t i=0; i<this->size_; ++i) {
        this->ary[i] = src.ary[i];
    }
}

DynamicIntArray::DynamicIntArray(const DynamicIntArray& src)
        : ary(nullptr), size_(src.size_), capacity_(src.capacity_) {
    setup_copy(src);
}

DynamicIntArray& DynamicIntArray::operator=(const DynamicIntArray& src) {
    if (this != &src) { // self assignment check
        delete [] ary;
        this->size_ = src.size_;
        this->capacity_ = src.capacity_;
        setup_copy(src);
    }
    return *this;
}