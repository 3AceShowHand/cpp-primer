//
// Created by king on 2019/4/25.
//


#include <memory>
#include <string>
#include <iostream>
#include <list>

using namespace std;


int main() {

    shared_ptr<string> p1;
    if (p1 == nullptr) {
        cout << "p1 is nullptr" << endl;
    }

    shared_ptr<list<int>> ptr2;

    shared_ptr<int> ptr3 = make_shared<int>(42);
    cout  << *ptr3 << endl;

    shared_ptr<string> ptr4 = make_shared<string>(10, '9');
    cout << *ptr4 << endl;

    shared_ptr<int> ptr5 = make_shared<int>();
    cout << *ptr5 << endl;

    auto r = make_shared<int>(42);
    r = ptr3;
    cout << r.use_count() << endl;

    return 0;
}