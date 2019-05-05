//
// Created by king on 2019/5/5.
//

#include <memory>
#include "Unique_ptr.hpp"

using namespace std;

void func1() {
    Unique_ptr<int> p1;

    Unique_ptr<int> p2(new int(3));

    int a = 3;
    Unique_ptr<int> p3(&a);
    // p3 = p2;                    overload resolution selected deleted operator '='
    // Unique_ptr<int> p4(p3); call to deleted constructor
}

void func2() {
    unique_ptr<int> p1;
    unique_ptr<int> p2(new int(3));
    int a = 3;
    unique_ptr<int> p3(&a);

    // p3 = p2;                     overload resolution selected deleted operator '='
    // unique_ptr<int> p4(p3);  call to deleted constructor

}

int main() {

    func2();

    return 0;
}