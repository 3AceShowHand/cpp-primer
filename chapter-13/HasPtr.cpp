//
// Created by king on 2019/4/26.
//

#include "HasPtr.hpp"

using namespace std;

HasPtr::HasPtr(const string &s) : ps(new std::string(s)), i(0) {

}

HasPtr::HasPtr(const HasPtr &rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) {

}

HasPtr &HasPtr::operator=(const HasPtr &rhs) {
    auto newps = new std::string(*rhs.ps);
    delete ps;
    ps = newps;
    i = rhs.i;

    return *this;
}
