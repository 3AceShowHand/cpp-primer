//
// Created by king on 2019/5/5.
//

#include <iostream>

template <class T, unsigned N>
constexpr unsigned getArraySize(const T(&arr)[N]) {
    return N;
}

int main() {
    int arr[] = {1, 3, 5};
    std::cout << getArraySize(arr) << std::endl;
    
    double arr2[] = {3.14, 2.72};
    std::cout << getArraySize(arr2) << std::endl;
    
    return 0;
}