//
// Created by king on 2019/5/5.
//

#include <iostream>

template <class T_Iter, unsigned N>
T_Iter* begin(T_Iter(&arr)[N]) {
    return arr;
}

template <class T_Iter, unsigned N>
T_Iter* end(T_Iter(&arr)[N]) {
    return &(arr[N]);
}

template <class T_Iter, unsigned N>
const T_Iter* cbegin(const T_Iter(&arr)[N]) {
    return arr;
}

template <class T_Iter, unsigned N>
const T_Iter* cend(const T_Iter(&arr)[N]) {
    return &arr[N];
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int* beg = begin(arr);
    int* e = end(arr);

    while (beg != e) {
        std::cout << *beg << " ";
        ++beg;
    }
    std::cout << std::endl;

    for (auto iter = cbegin(arr); iter != cend(arr); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;

    return 0;
}