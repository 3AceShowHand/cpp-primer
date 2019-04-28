//
// Created by king on 2019/4/26.
//

#ifndef CPP_PRIMER_HASPTR_HPP
#define CPP_PRIMER_HASPTR_HPP

#include <string>
#include <iostream>

/*
 * This is a value like version of HasPtr
 * copy constructor and copy assignment will not share the same underline memory.
 * each object have their own version
*/

class HasPtr {

    friend void swap(HasPtr&, HasPtr&);

public:

    HasPtr(const std::string& s = std::string());

    HasPtr(const HasPtr& rhs);
    // HasPtr& operator=(HasPtr rhs);
    HasPtr& operator=(HasPtr& rhs);

    HasPtr(HasPtr&& p) noexcept;
    HasPtr& operator=(HasPtr&& rhs) noexcept ;

    bool operator<(const HasPtr& rhs);

    ~HasPtr();

private:

    std::string* ps;
    int i;

};

inline void swap(HasPtr& lhs, HasPtr& rhs) {
    std::cout << " swap(HasPtr& lhs, HasPtr& rhs) called " << std::endl;
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

#endif //CPP_PRIMER_HASPTR_HPP
