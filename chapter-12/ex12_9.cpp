//
// Created by king on 2019/4/25.
//

#include <memory>
#include <iostream>

using namespace std;


int main() {

    int* q = new int(42), *r = new int(100);
    r = q; // memory leak will happen here, original memory pointed by r will be lost and cannot be freed in the future.
    auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
    r2 = q2;

    return 0;
}
