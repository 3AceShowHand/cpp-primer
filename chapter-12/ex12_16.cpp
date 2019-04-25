//
// Created by king on 2019/4/25.
//

#include <iostream>
#include <memory>
#include <string>

using namespace std;


int main() {

    unique_ptr<string> p1(new string("halo"));
    cout << *p1 << endl;

    // cannot copy and assgin a unique_ptr

    // error: use of deleted function 'std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&)
    // unique_ptr<string> p2(p1); //copy

    // error: use of deleted function 'std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&)
    // unique_ptr<string> p3 = p1; // assign

    p1.reset(nullptr);
    if (!p1) {
        cout << "p1 is nullptr" << endl;
    }

    return 0;
}