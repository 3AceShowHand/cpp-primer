//
// Created by king on 2019/5/5.
//

#include <iostream>

void static_cast_case() {
    int i = 3;
    int j = 5;
    double slope = static_cast<double>(j) / i;

    void* p = &slope;
    double* dp = static_cast<double*>(p);
}

void const_cast_case() {
    const char* pc = "hello world";
    char* p = const_cast<char*>(pc);
}

void reinterpret_cast_case() {
    int* ip;
    char* pc = reinterpret_cast<char*>(ip);
}

int main() {

    return 0;
}
