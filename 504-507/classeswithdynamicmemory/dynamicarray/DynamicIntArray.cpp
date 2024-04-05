#include "DynamicIntArray.h"

DynamicIntArray::DynamicIntArray(size_t size, int val) {

}

void DynamicIntArray::increaseCapacity(size_t newCapacity) {
    if (capacity_ == 0) {
        if (newCapacity == 0)
            capacity_ = 1;
        else 
            capacity_ = newCapacity;
        ary = new int[capacity_];
        return;
    }
    else {
        // need to deal with newCapacity here
        size_t newCapacity = capacity_ * 2;

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
}