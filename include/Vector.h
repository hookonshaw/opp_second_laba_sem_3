#pragma once

#include <cstddef>


class DynamicArray {
private:
    unsigned char* data_;
    size_t size_;
    size_t capacity_;

    void resize(size_t new_capacity);

public:
    DynamicArray();
    ~DynamicArray();
    DynamicArray(const DynamicArray& other);
    void push_back(unsigned char value);
    unsigned char get(size_t index) const;
    void set(size_t index, unsigned char value);
    size_t getSize() const;
    size_t getCapacity() const;
    void pop_back();
    bool isEmpty() const;
    void clear();
};