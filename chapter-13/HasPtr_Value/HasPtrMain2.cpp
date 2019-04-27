//
// Created by king on 2019/4/27.
//


#include <vector>
#include <algorithm>

#include "HasPtr.hpp"

using namespace std;

int main() {

    HasPtr ptr1("23");
    HasPtr ptr2 = ptr1;
    HasPtr ptr3;
    ptr3 = ptr1;

    HasPtr a("45"), b("34"), c("21"), d("5");
    vector<HasPtr> vec{a, b, c, d};
    std::sort(vec.begin(), vec.end()); // swap will be called.

    return 0;
}