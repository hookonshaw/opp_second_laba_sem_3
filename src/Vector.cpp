#include "Vector.h"


DynamicArray::DynamicArray() : data_(nullptr), size_(0), capacity_(0) {}

DynamicArray::~DynamicArray(){
    delete[] data_;
}

DynamicArray::DynamicArray(const DynamicArray& other) : data_(other.data_), size_(other.size_), capacity_(other.capacity_)

{
    if (capacity_ > 0){
        data_ = new unsigned char [capacity_];
        for (size_t i = 0; i < size_; i++){
            data_[i] = other.data_[i];
        }
    }
}

void DynamicArray::resize(size_t new_capacity) {
    if (new_capacity <= capacity_) {
        return;
    }
    unsigned char* new_data = new unsigned char[new_capacity];
    for (size_t i = 0; i < size_; ++i) {
        new_data[i] = data_[i];
    }
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
}

void DynamicArray::push_back(unsigned char value){
    if (size_ >= capacity_){
        size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
        resize(new_capacity);
    }
    data_[size_] = value;
    ++size_;
}


unsigned char DynamicArray::get(size_t index) const{
    if (index >= size_){
        return 0;
    }
    return data_[index];
}

void DynamicArray::set(size_t index, unsigned char value){
    if (index >= size_){
        return;
    }
    data_[index] = value;
}

size_t DynamicArray::getSize() const{
    return size_;
}

size_t DynamicArray::getCapacity() const{
    return capacity_;
}

void DynamicArray::pop_back() {
    if (size_ > 0){
        --size_;
    }
}

bool DynamicArray::isEmpty() const{
    return size_ == 0;
}

void DynamicArray::clear(){
    size_ = 0;
}