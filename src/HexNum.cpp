#include "HexNum.h"
#include <iostream>
#include <algorithm>
#include <stdexcept>

HexNum::HexNum() {
    digits_.push_back(0);
}

HexNum::HexNum(const std::string& hex_str){
    if (hex_str.empty()) {
        digits_.push_back(0);
        return;
        
    }

    for (int i = hex_str.length() - 1; i >= 0; i--){
        char c = hex_str[i];
        unsigned char digit;

        if (c >= '0' && c <= '9'){
            digit = c - '0';
        } else if (c >= 'A' && c <= 'F'){
            digit = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f'){
            digit = c - 'a' + 10;
    }else{
        return;
    }
    digits_.push_back(digit);
    }
    while (digits_.getSize() > 1 && digits_.get(digits_.getSize() - 1) == 0){
        digits_.pop_back();
    }
}

HexNum::HexNum(const HexNum& other): digits_(other.digits_){
}

void HexNum::print() const{
    if(is_zero()){
        std::cout << '0';
        return;
    }

    for (int i = digits_.getSize() - 1; i >= 0; i--){
        unsigned char digit = digits_.get(i);
        if (digit < 10){
            std::cout << static_cast<char>('0' + digit);
        }else {
            std::cout << static_cast<char>('A' + (digit - 10));
        }
    }
}

size_t HexNum::get_size() const{
    return digits_.getSize();
}

unsigned char HexNum::get_digit(size_t index) const{
    if(index >= digits_.getSize()){
        return 0;
    }
    return digits_.get(index);
}

void HexNum::set_digit(size_t index, unsigned char digit) {
    if (digit >= 16) {
        return;
    }
    
    if (index < digits_.getSize()) {
        digits_.set(index, digit);
    } else {
        while (digits_.getSize() <= index) {
            digits_.push_back(0);
        }
        digits_.set(index, digit);
    }
}


bool HexNum::is_zero() const {
    return (digits_.getSize() == 1) && (digits_.get(0) == 0);
}

HexNum add(const HexNum& a, const HexNum& b) {
    HexNum result;
    size_t max_size = std::max(a.get_size(), b.get_size());
    unsigned char carry = 0;
    
    for (size_t i = 0; i < max_size; ++i) {
        unsigned char sum = a.get_digit(i) + b.get_digit(i) + carry;
        result.set_digit(i, sum % 16);
        carry = sum / 16;
    }
    
    if (carry > 0) {
        result.set_digit(max_size, carry);
    }
    
    return result;
}

HexNum sub(const HexNum& a, const HexNum& b) {
    if (less(a, b)) {
        return HexNum();
    }
    
    HexNum result;
    unsigned char borrow = 0;
    size_t max_size = a.get_size();
    
    for (size_t i = 0; i < max_size; ++i) {
        int diff = a.get_digit(i) - b.get_digit(i) - borrow;
        
        if (diff < 0) {
            diff += 16;
            borrow = 1;
        } else {
            borrow = 0;
        }
        
        result.set_digit(i, diff);
    }

    while (result.get_size() > 1 && result.get_digit(result.get_size() - 1) == 0) {
        break;
    }
    
    return result;
}

bool equals(const HexNum& a, const HexNum& b) {
    if (a.get_size() != b.get_size()) {
        return false;
    }
    
    for (size_t i = 0; i < a.get_size(); ++i) {
        if (a.get_digit(i) != b.get_digit(i)) {
            return false;
        }
    }
    return true;
}

bool greater(const HexNum& a, const HexNum& b) {
    if (a.get_size() != b.get_size()) {
        return a.get_size() > b.get_size();
    }
    
    for (int i = a.get_size() - 1; i >= 0; --i) {
        if (a.get_digit(i) > b.get_digit(i)) {
            return true;
        }
        if (a.get_digit(i) < b.get_digit(i)) {
            return false;
        }
    }
    return false;
}


bool less(const HexNum& a, const HexNum& b) {
    return !greater(a, b) && !equals(a, b);
}