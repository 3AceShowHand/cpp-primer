//
// Created by king on 2019/4/26.
//

#ifndef CPP_PRIMER_FOO_HPP
#define CPP_PRIMER_FOO_HPP

#include <vector>

class Foo {

public:
    Foo sorted() && ;
    Foo sorted() const &;

private:
    std::vector<int> data;
};



#endif //CPP_PRIMER_FOO_HPP
