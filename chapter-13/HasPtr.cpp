//
// Created by king on 2019/4/26.
//

#include "HasPtr.hpp"

using namespace std;


HasPtr::HasPtr(const string &s): ps(new std::string(s)), i(0), use_count(new std::size_t(1)) {

}

HasPtr::HasPtr(const HasPtr &rhs): ps(rhs.ps), i(0), use_count(rhs.use_count) {
    *use_count += 1;
}

HasPtr &HasPtr::operator=(const HasPtr &rhs) {
    *rhs.use_count += 1;
    if (--*use_count == 0) {
        delete ps;
        delete use_count;
    }
    ps = rhs.ps;
    i = rhs.i;
    use_count = rhs.use_count;

    return *this;
}

HasPtr::~HasPtr() {
    *use_count -= 1;
    if (*use_count == 0) {
        delete ps;
        delete use_count;
    }
}
