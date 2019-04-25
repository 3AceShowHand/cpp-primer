//
// Created by king on 2019/4/25.
//

#include <memory>
#include <string>
#include <iostream>

using namespace std;

int main() {

    unique_ptr<string> p1(new string("Stegosaurus"));
    cout << "p1 is : " << *p1 << endl;

    unique_ptr<string> p2(p1.release());
    cout << "p2 is : " << *p2 << endl;
    if (p1 == nullptr) {
        cout << "p1 is nullptr" << endl;
    }

    unique_ptr<string> p3(new string("Trex"));
    cout << "p3 is : " << *p3 << endl;

    p2.reset(p3.release());
    cout << "p2 is : " << *p2 << endl;
    if (p3 == nullptr) {
        cout << "p3 is nullptr" << endl;
    }


    return 0;
}