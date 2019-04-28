//
// Created by king on 2019/4/28.
//

#include <iostream>

using namespace std;


int main() {
    int&& rr1 = 42;

    const int& ci = rr1;   // const lvalue reference can bind to a rvalue reference.
    cout << ci << endl;

    // int&& rr2 = rr1;    // rr1 is a lvalue, each variable is lvalue, even it is a rvalue reference.
    int&& rr3 = std::move(rr1); // we can use move to get the rvalue reference of a lvalue

    cout << rr1 << endl;
    cout << rr3 << endl;

    return 0;
}