//
// Created by king on 2019/5/5.
//

#include <iostream>
#include <memory>

#include "Shared_ptr.hpp"

using namespace std;

void func1() {
    shared_ptr<int> p;
    cout << p.use_count() << endl;
    if (p.get() == nullptr) {
        cout << "p.get() == nullptr" << endl;
    }

    if (p == nullptr) {
        cout << "p == nullptr" << endl;
    }
}


int main() {

    Shared_ptr<int> p1;
    Shared_ptr<int> p2(new int(1));

    return 0;
}