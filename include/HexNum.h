#pragma once

#include "Vector.h"

#include <string>

class HexNum {
private:
    DynamicArray digits_;

public:
    HexNum();
    HexNum(const std::string& hex_str);
    HexNum(const HexNum& other);
    void print() const;

    size_t get_size() const;
    unsigned char get_digit(size_t index) const;
    void set_digit(size_t index, unsigned char digit);

    bool is_zero() const;
};

HexNum add(const HexNum& num1, const HexNum& num2);
HexNum sub(const HexNum& num1, const HexNum& num2);

bool equals(const HexNum& num1, const HexNum& num2);
bool greater(const HexNum& num1, const HexNum& num2);
bool less(const HexNum& num1, const HexNum& num2);