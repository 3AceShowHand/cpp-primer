//
// Created by king on 2019/4/26.
//

#include "HasPtr.hpp"

using namespace std;


HasPtr::HasPtr(const string &s): ps(new std::string(s)), i(0) {

}

HasPtr::HasPtr(const HasPtr &rhs) : ps(new std::string(*rhs.ps)), i(0) {

}

HasPtr& HasPtr::operator=(HasPtr rhs) {
    swap(*this, rhs);
    return *this;
}

bool HasPtr::operator<(const HasPtr &rhs) {
    return this->i < rhs.i;
}

HasPtr::~HasPtr() {
    delete ps;
}
