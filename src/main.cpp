#include "HexNum.h"

#include <iostream>
#include <string>

int main() {
    std::string a_str;
    std::string b_str;
    std::cin >> a_str;
    std::cin >> b_str;

    HexNum a(a_str);
    HexNum b(b_str);
    
    HexNum res_plus = add(a, b);
    std::cout << "Сумма: ";
    res_plus.print();
    std::cout << std::endl;
    
    HexNum res_sub = sub(a, b);
    std::cout << "Разность: ";
    res_sub.print();
    std::cout << std::endl;
    
    return 0;
}