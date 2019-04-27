//
// Created by king on 2019/4/26.
//

#include <iostream>
#include <vector>

using namespace std;


struct  X {

    X() {
        cout << " X() default constructor " << endl;
        cout << endl;
    }

    X(const X& n) {
        cout << " X(const X& n) copy constructor " << endl;
        cout << endl;
    }

    ~X() {
        cout << " ~X() deconstructor " << endl;
        cout << endl;
    }

    X& operator=(const X& n) {
        cout << " operator=(const X& n) copy assignment " << endl;
        cout << endl;
        return *this;
    }
};

void func1(X n) {
    cout << " non-reference pass " << endl;
    cout << endl;
}

void func2(X& n) {
    cout << " reference pass " << endl;
    cout << endl;
}

void func3() {
    cout << "dynamic new called" << endl;
    cout << endl;
    X* p = new X;
    delete p;
}

int main() {

    cout << " x1 create " << endl;
    X x1;

    cout << " x2 create " << endl;
    X x2(x1);

    cout << " x3 create " << endl;
    X x3;
    x3 = x1;

    cout << " x4 create " << endl;
    X x4 = x1;

    cout << " func1(x1) create " << endl;
    func1(x1);

    cout << " func2(x2) create " << endl;
    func2(x2);

    cout << " func3() create " << endl;
    func3();

    cout << "vector<X> create " << endl;
    vector<X> v{x1, x2, x3};

    return 0;
}