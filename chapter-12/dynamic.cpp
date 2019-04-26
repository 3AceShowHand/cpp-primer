//
// Created by king on 2019/4/25.
//

#include <iostream>
#include <memory>

using namespace std;


int main() {

    int* pia = new int[10];
    for (int i = 0; i < 10; ++i) {
        cout << pia[i] << " ";
    }
    cout << endl;
    delete[] pia;

    int* pia2 = new int[10];
    for (int i = 0; i < 10; ++i) {
        cout << pia2[i] << " ";
    }
    cout << endl;
    delete[] pia2;

    unique_ptr<int[]> up(new int[10]);
    up.release();

    shared_ptr<int> sp(new int[10], [](int* p) {delete[] p;});
    for (size_t i = 0; i != 10; ++i) {
        *(sp.get() + i) = i;
    }
    
    return 0;
}