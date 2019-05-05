//
// Created by king on 2019/5/5.
//

#ifndef CPP_PRIMER_Shared_ptr_HPP
#define CPP_PRIMER_Shared_ptr_HPP

/* This is a simple implementation of shared_ptr,
 * only some method implemented, just a toy.
*/
#include <iostream>

template <class T>
class Shared_ptr {
    using element_type = T;
    using weak_type = std::weak_ptr<T>;

public:
    constexpr Shared_ptr() noexcept :resource(nullptr), counter(nullptr) {
        std::cout << "Shared_ptr()" << std::endl;
    }

    constexpr Shared_ptr(std::nullptr_t) noexcept :Shared_ptr() {
        std::cout << "Shared_ptr(std::nullptr)" << std::endl;
    }

    Shared_ptr(element_type* t):resource(t), counter(new std::size_t(1)) {
        std::cout << "Shared_ptr(element_type* t)" << std::endl;
    }

    Shared_ptr(const Shared_ptr& other):resource(other.resource), counter(other.counter) {
        *counter += 1;
        std::cout << "Shared_ptr(const Shared_ptr& other)" << std::endl;
    }

    Shared_ptr& operator=(const Shared_ptr& other);

    ~Shared_ptr();

    T* get() {
        return resource;
    }

    std::size_t use_count() {
        if (counter == nullptr) {
            return 0;
        }
        return *(this->counter);
    }

private:
    element_type* resource;
    std::size_t* counter;
};

template<class T>
Shared_ptr<T> &Shared_ptr<T>::operator=(const Shared_ptr &other) {
    std::cout << "Shared_ptr<T>::operator=(const Shared_ptr &other)" << std::endl;
    *other.counter += 1;
    if (counter != nullptr) {
        if (--*counter == 0) {
            delete resource;
            delete counter;
        }
    }
    resource = other.resource;
    counter = other.counter;
    return *this;
}

template<class T>
Shared_ptr<T>::~Shared_ptr() {
    std::cout << "~Shared_ptr()" << std::endl;
    if (counter != nullptr) {
        *counter -= 1;
        if (0 == use_count()) {
            std::cout << "delete old resource and count" << std::endl;
            delete counter;
            delete resource;
        }
    }
}

#endif //CPP_PRIMER_Shared_ptr_HPP
