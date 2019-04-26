//
// Created by king on 2019/4/26.
//

#ifndef CPP_PRIMER_HASPTR_HPP
#define CPP_PRIMER_HASPTR_HPP

#include <string>


class HasPtr {

public:

    HasPtr(const std::string& s = std::string());
    HasPtr(const HasPtr& rhs);

    HasPtr& operator=(const HasPtr& rhs);

private:
    std::string* ps;
    int i;

};


#endif //CPP_PRIMER_HASPTR_HPP
