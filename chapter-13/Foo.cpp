//
// Created by king on 2019/4/26.
//

#include <algorithm>
#include <iostream>

#include "Foo.hpp"


Foo Foo::sorted() &&{
    std::cout << " Foo::sorted() && " << std::endl;

    std::sort(data.begin(), data.end());
    return *this;
}

Foo Foo::sorted() const & {
    std::cout << " Foo::sorted() const & " << std::endl;

    return Foo(*this).sorted();
}

//Foo Foo::sorted() const &{
//    std::cout << " Foo:sorted() const & " << std::endl;
//
//    Foo ret(*this);
//    std::sort(ret.data.begin(), ret.data.end());
//    return ret;
//}


int main() {

    Foo f;     // lvalue
    f.sorted();    // "Foo::sorted() const &" called.

    return 0;
}
