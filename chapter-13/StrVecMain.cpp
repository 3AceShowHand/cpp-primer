//
// Created by king on 2019/4/27.
//

#include <iostream>
#include "StrVec.hpp"

using namespace std;

int main() {

    StrVec v1;
    StrVec v2(v1);
    StrVec v3;
    v3 = v1;

    v1.push_back("aha");
    cout << "size = " << v1.size() << "capaticy = " << v1.capacity() << endl;

    v1.push_back("halo");
    cout << "size = " << v1.size() << "capaticy = " << v1.capacity() << endl;

    v1.push_back("fuck");
    cout << "size = " << v1.size() << "capaticy = " << v1.capacity() << endl;

    v1.resize(10, "###");
    cout << "size = " << v1.size() << "capaticy = " << v1.capacity() << endl;

    v1.reserve(10);
    cout << "size = " << v1.size() << "capaticy = " << v1.capacity() << endl;

    v1.reserve(50);
    cout << "size = " << v1.size() << "capaticy = " << v1.capacity() << endl;

    v1.shrink_to_fit();
    cout << "size = " << v1.size() << "capaticy = " << v1.capacity() << endl;

    return 0;
}