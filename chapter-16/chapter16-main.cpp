//
// Created by king on 2019/5/4.
//

#include <cstring>
#include <functional>
#include <iostream>
#include "Sales_data.h"

using namespace std;

// 非类型模板参数
template <unsigned N, unsigned M>
int compare(const char(&p1)[N], const char(&p2)[M]) {
    return strcmp(p1, p2);
}

template <typename T>
int compare(const T& v1, const T& v2) {
    if (less<T>()(v1, v2)) return -1;
    if (less<T>()(v2, v1)) return 1;
    return 0;
}

int main() {

    std::cout << compare("abc", "ab") << std::endl;

    std::cout << compare(string("abc"), string("ab")) << std::endl;

    std::cout << compare(10, 5) << std::endl;
    std::cout << compare(0.01, 0.15) << std::endl;
    std::cout << compare(1.72731858, 3.1415926) << std::endl;

    Sales_data a, b;
    // template argument deduction/substitution failed
    //   note: candidate: 'template<class _CharT, class _Traits, class _Alloc> bool std::operator<(const std::__cxx11::basic_string<_CharT, _Traits, _Alloc>&, const _CharT*)'
    //   operator<(const basic_string<_CharT, _Traits, _Alloc>& __lhs
    // std::cout << compare(a, b) << std::endl;    // Sales_data does not support "<" operand.

    return 0;
}