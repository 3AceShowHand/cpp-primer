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

void func2() {
    Shared_ptr<int> p1;
    std::cout << p1.use_count() << std::endl;

    Shared_ptr<int> p2(new int(1));
    std::cout << p2.use_count() << std::endl;

    Shared_ptr<int> p3(p2);
    std::cout << p2.use_count() << std::endl;
    std::cout << (p3.use_count() == p2.use_count()) << std::endl;
}

int main() {

    Shared_ptr<string> p1(new string("hello"));
    Shared_ptr<string> p2(p1);
    Shared_ptr<string> p3;
    p3 = p1;

    return 0;
}