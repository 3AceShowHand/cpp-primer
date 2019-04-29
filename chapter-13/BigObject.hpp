//
// Created by king on 2019/4/28.
//

#ifndef CPP_PRIMER_BIGOBJECT_HPP
#define CPP_PRIMER_BIGOBJECT_HPP


#include <iostream>

class BigObject {
public:
    BigObject() {
        std::cout << " constructor. " << std::endl;
    }

    ~BigObject() {
        std::cout << " destructor. " << std::endl;
    }

    BigObject(const BigObject& ) {
        std::cout << " copy constructor " << std::endl;
    }

    BigObject(BigObject&&) {
        std::cout << " move constructor " << std::endl;
    }
};


#endif //CPP_PRIMER_BIGOBJECT_HPP
