//
// Created by king on 2019/4/26.
//

#include <iostream>

#include "numbered.hpp"

using namespace std;

numbered::numbered(): mysn(sn_manager++) {

}

numbered::numbered(const numbered &x): mysn(sn_manager++) {

}

void f(const numbered& s) {
    cout << s.getMysn() << endl;
}

int main() {

    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);

    return 0;
}
