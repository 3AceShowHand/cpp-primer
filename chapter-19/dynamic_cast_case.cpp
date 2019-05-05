//
// Created by king on 2019/5/5.
//

#include <iostream>

using namespace std;

class Base {

public:
    virtual void foo() {
        cout << "Base::foo()" << endl;
    }

};


class Derived: public Base {

public:
    void foo() override {
        cout << "Derived::foo()" << endl;
    }
};

void func() {
    Base b;
    Base* bp = &b;
    if (Derived* dp = dynamic_cast<Derived*>(bp)) {
        std::cout << "dynamic_cast<Derived*> succeed." << std::endl;
    } else {
        std::cout <<" dynamic_cast failed." << std::endl;
    }

    Base* bp2 = new Base;
    if (Derived* dp2 = dynamic_cast<Derived*>(bp2)) {
        std::cout << "dynamic_cast<Derived*> succeed." << std::endl;
    } else {
        std::cout <<"dynamic_cast failed." << std::endl;
    }
    delete bp2;
}

void func2(const Base& b) {
    try {
        const Derived& d = dynamic_cast<const Derived&>(b);
        cout << "dynamic_cast<const Derived&>(b)" << endl;
    } catch (bad_cast) {
        cout << "dynamic_cast<const Derived&>(b) failed" << endl;
    }
}


int main() {

    func();
    Base a;
    func2(a);

    return 0;
}