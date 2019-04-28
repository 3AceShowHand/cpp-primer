//
// Created by king on 2019/4/26.
//

#include "HasPtr.hpp"

using namespace std;


HasPtr::HasPtr(const string &s): ps(new std::string(s)), i(0) {

}

HasPtr::HasPtr(const HasPtr &rhs) : ps(new std::string(*rhs.ps)), i(0) {

}

//HasPtr& HasPtr::operator=(HasPtr rhs) {
//    swap(*this, rhs);
//    return *this;
//}

HasPtr &HasPtr::operator=(HasPtr &rhs) {
    if (this != &rhs) {
        delete this->ps;
        this->ps = new std::string(*rhs.ps);
        this->i = rhs.i;
    }
    return *this;
}

HasPtr &HasPtr::operator=(HasPtr &&rhs) noexcept {
    std::cout << " operator=(HasPtr&& rhs) called " << std::endl;
    if (this != &rhs) {
        delete this->ps;

        this->ps = rhs.ps;
        this->i = rhs.i;
        rhs.ps = nullptr;
    }
    return *this;
}

bool HasPtr::operator<(const HasPtr &rhs) {
    return this->i < rhs.i;
}

HasPtr::HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) {
    std::cout << " HasPtr(HasPtr&& p) called " << std::endl;
    p.ps = 0;
}

HasPtr::~HasPtr() {
    delete ps;
}
