//
// Created by king on 2019/5/5.
//

#ifndef CPP_PRIMER_Shared_ptr_HPP
#define CPP_PRIMER_Shared_ptr_HPP

#include <cstddef>
#include <iostream>

template <class T>
class Shared_ptr {
    using element_type = T;
    using weak_type = std::weak_ptr<T>;

public:
    constexpr Shared_ptr() noexcept :resource(nullptr), count(new std::size_t(0)) {
        std::cout << "Shared_ptr()" << std::endl;
    }

    constexpr Shared_ptr(std::nullptr_t) noexcept :Shared_ptr() {
        std::cout << "Shared_ptr(std::nullptr)" << std::endl;
    }

    Shared_ptr(element_type* t):resource(t), count(new std::size_t(1)) {
        std::cout << "Shared_ptr(element_type* t)" << std::endl;
    }

    Shared_ptr(const Shared_ptr& other) {

    }

    Shared_ptr& operator=(const Shared_ptr& other);

    ~Shared_ptr() {
        std::cout << "~Shared_ptr()" << std::endl;
        if (0 == use_count()) {
            delete count;
            delete resource;
        } else {
            *count -= 1;
        }
    }

    T* get() {
        return resource;
    }

    std::size_t use_count() {
        return *(this->count);
    }

private:
    element_type* resource;
    std::size_t* count;
};

#endif //CPP_PRIMER_Shared_ptr_HPP
