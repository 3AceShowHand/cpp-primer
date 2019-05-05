//
// Created by king on 2019/5/5.
//

#ifndef CPP_PRIMER_UNIQUE_PTR_HPP
#define CPP_PRIMER_UNIQUE_PTR_HPP

#include <iostream>

template <class T>
class Unique_ptr {
    using element_type = T;

public:
    Unique_ptr():resource(nullptr) {
        std::cout << "Unique_ptr()" << std::endl;
    }

    Unique_ptr(element_type* t): resource(t) {
        std::cout << "Unique_ptr()" << std::endl;
    }

    Unique_ptr(const Unique_ptr& other) = delete;
    Unique_ptr& operator=(Unique_ptr& other) = delete;

    ~Unique_ptr() {
        std::cout << "~Unique_ptr()" << std::endl;
        if (resource != nullptr) {
            delete resource;
        }
    }

private:
    T* resource;
};

#endif //CPP_PRIMER_UNIQUE_PTR_HPP
