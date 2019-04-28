//
// Created by king on 2019/4/28.
//

#include <cstring>
#include <algorithm>
#include <iostream>
#include "String.hpp"

std::allocator<char> String::alloc;

std::pair<char *, char *> String::alloc_n_copy(const char *b, const char *e) {
    auto str = alloc.allocate(e - b);
    return {str, std::uninitialized_copy(b, e, str)};
}

void String::free() {
    if (elements) {
        std::for_each(elements, first_free, [this](char &c) {
            alloc.destroy(&c);
        });
        alloc.deallocate(elements, first_free - elements);
    }
}

String::String(const char *cstr) {
    char* end = const_cast<char*>(cstr) + strlen(cstr);
    auto newstr = alloc_n_copy(cstr, end);
    elements = newstr.first;
    first_free = newstr.second;
}

String::String(const String &that) {
    std::cout << " String(const String& that) called " << std::endl;

    auto newstr = alloc_n_copy(that.begin(), that.end());
    elements = newstr.first;
    first_free = newstr.second;
}

String &String::operator=(const String &that) {
    std::cout << " operator=(const String& that) called " << std::endl;

    auto newstr = alloc_n_copy(that.begin(), that.end());
    free();
    elements = newstr.first;
    first_free = newstr.second;

    return *this;
}

String::~String() {
    free();
}

String::String(String &&s) noexcept :elements(s.elements), first_free(s.first_free) {
    std::cout << "String(String &&s) called " << std::endl;
    s.elements = s.first_free = nullptr;
}

String &String::operator=(String&& rhs) noexcept {
    std::cout << " operator=(String&& rhs) called " << std::endl;

    if (this != &rhs) {
        this->free();
        this->elements = rhs.elements;
        this->first_free = rhs.first_free;

        rhs.elements = rhs.first_free = nullptr;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const String &s) {
    os << s.elements << std::endl;
    return os;
}

bool operator==(const String &lhs, const String &rhs) {
    return  (lhs.size() == rhs.size()) && std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

bool operator!=(const String &lhs, const String &rhs) {
    return !(lhs == rhs);
}

bool operator<(const String &lhs, const String &rhs) {
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

bool operator>(const String &lhs, const String &rhs) {
    return lhs < lhs;
}

bool operator<=(const String &lhs, const String &rhs) {
    return !(lhs > rhs);
}

bool operator>=(const String &lhs, const String &rhs) {
    return !(lhs < rhs);
}

