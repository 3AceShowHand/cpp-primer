//
// Created by king on 2019/4/28.
//

#include <algorithm>
#include "BigObject.hpp"


BigObject foo() {
    BigObject localObj;
    return localObj;
}

BigObject&& foo(int n) {
    BigObject localObj;
    return std::move(localObj);
}


int main() {
    BigObject obj = foo(1);

    return 0;
}