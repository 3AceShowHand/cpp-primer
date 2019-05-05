//
// Created by king on 2019/5/5.
//

#include "DebugDelete.hpp"


int main() {
    double* p = new double;
    DebugDelete d;
    d(p);
    int* t = new int;
    d(t);

    return 0;
}