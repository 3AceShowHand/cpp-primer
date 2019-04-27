//
// Created by king on 2019/4/26.
//

#include "HasPtr.hpp"

using namespace std;


int main() {
    HasPtr ptr1;
    HasPtr ptr2 = ptr1;
    HasPtr ptr3;
    ptr3 = ptr1;

    return 0;
}