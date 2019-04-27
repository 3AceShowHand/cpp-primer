//
// Created by king on 2019/4/27.
//


#include <utility>
#include <algorithm>
#include "StrVec.hpp"

using namespace std;

std::allocator<std::string> StrVec::alloc;

StrVec::StrVec(const StrVec & sv) {
    range_initialize(sv.begin(), sv.end());
}

StrVec &StrVec::operator=(const StrVec & sv) {
    auto newData = alloc_n_copy(sv.begin(), sv.end());
    free();
    elements = newData.first;
    first_free = newData.second;
    cap = first_free;

    return *this;
}

StrVec::StrVec(std::initializer_list<std::string> sl) {
    range_initialize(sl.begin(), sl.end());
}

StrVec::~StrVec() {
    free();
}

void StrVec::push_back(const std::string & s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

void StrVec::free() {
    if (elements) {
        for_each(elements, first_free, [this](std::string& s) {
            alloc.destroy(&s);
        });
        alloc.deallocate(elements, cap - elements);
    }
}

std::pair<std::string *, std::string *> StrVec::alloc_n_copy(const std::string* b, const std::string* e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::reallocate() {

    auto newcapaticy = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapaticy);  // allocate new raw memory

    auto dest = newdata;    // point to the first free of new raw memory
    auto elem = elements;   // point to the first place of old memory

//    for (size_t i = 0; i != size(); ++i) {
//        alloc.construct(dest++, std::move(*elem++));   // use the move constructor of elem
//    }
    for_each(dest, dest + size(), [this, &elem] (std::string& s) {
        alloc.construct(&s, std::move(*elem++));
    });

    free();  // free old memory

    elements = newdata;   // set pointers to new data memory
    first_free = dest;
    cap = elements + newcapaticy;
}

void StrVec::resize(int newSize) {
    resize(newSize, "");
}

void StrVec::resize(int newSize, const std::string &t) {
    if (newSize > size()) {
        if (newSize > capacity()) {
            reserve(newSize * 2);
        }
        for (size_t i = size(); i != newSize; ++i) {
            alloc.construct(first_free++, t);
        }
    } else if (newSize < size()) {
        while (first_free != elements + newSize) {
            alloc.destroy(--first_free);
        }
    }

}

void StrVec::reserve(int newCapacity) {
    if (newCapacity > capacity()) {
        auto newdata = alloc.allocate(newCapacity);
        auto dest = newdata;
        auto elem = elements;
        for (size_t i = 0; i != size(); ++i) {
            alloc.construct(dest++, std::move(*elem++));
        }
//        for_each(dest, dest + size(), [this, &elem] (std::string& s) {
//            alloc.construct(&s, std::move(*elem++));
//        });

        free();
        elements = newdata;
        first_free = dest;
        cap = elements + newCapacity;
    }
}

void StrVec::shrink_to_fit() {
    if (capacity() > size()) {
        auto newdata = alloc.allocate(size());
        auto dest = newdata;
        auto elem = elements;

        for (size_t i = 0; i != size(); ++i) {
            alloc.construct(dest++, std::move(*elem++));
        }

        free();
        elements = newdata;
        first_free = dest;
        cap = first_free;
    }
}

void StrVec::range_initialize(const std::string *begin, const std::string *end) {
    auto newData = alloc_n_copy(begin, end);
    elements = newData.first;
    first_free = cap = newData.second;
}

