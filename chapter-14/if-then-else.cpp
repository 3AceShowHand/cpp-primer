//
// Created by king on 2019/4/29.
//

#include <iostream>
using namespace std;

class If_then_else {
public:
    void operator() (bool cond, int first, int second) {
        if (cond) {
            cout << first << endl;
        } else {
            cout << second << endl;
        }
    }
};

int main() {
    If_then_else ite;
    ite(true, 1, 2);

    ite(false, 1, 2);

    return 0;
}