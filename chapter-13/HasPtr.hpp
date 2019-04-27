//
// Created by king on 2019/4/26.
//

#ifndef CPP_PRIMER_HASPTR_HPP
#define CPP_PRIMER_HASPTR_HPP

#include <string>
#include <iostream>


class HasPtr {

    friend void swap(HasPtr&, HasPtr&);

public:

    HasPtr(const std::string& s = std::string());
    HasPtr(const HasPtr& rhs);

    HasPtr& operator=(const HasPtr& rhs);
    // HasPtr& operator=(HasPtr rhs);

    ~HasPtr();

private:

    std::string* ps;
    int i;
    std::size_t*  use_count;
};

//inline void swap(HasPtr& lhs, HasPtr& rhs) {
//    std::cout << " swap(HasPtr& lhs, HasPtr& rhs) called " << std::endl;
//    using std::swap;
//    swap(lhs.ps, rhs.ps);
//    swap(lhs.i, rhs.i);
//}

#endif //CPP_PRIMER_HASPTR_HPP
