//
// Created by king on 2019/4/25.
//

#include <fstream>
#include <iostream>
#include "StrBlob.hpp"
#include "ConstStrBlobPtr.hpp"

using namespace std;


ConstStrBlobPtr::ConstStrBlobPtr():wptr(), curr(0) {

}

ConstStrBlobPtr::ConstStrBlobPtr(const StrBlob &sb, ConstStrBlobPtr::size_type pos)
:wptr(sb.data), curr(pos) {

}

std::shared_ptr<std::vector<std::string>>
ConstStrBlobPtr::check(size_type pos, const std::string &msg) const {
    auto ret = wptr.lock();
    if (!ret) {
        throw std::runtime_error("unbound ConstStrBlobPtr");
    }
    if (pos >= ret->size()) {
        throw std::out_of_range(msg);
    }
    return ret;
}

const std::string &ConstStrBlobPtr::deref() const {
    auto sp = check(curr, "deference past end of ConstStrBlobPtr");
    return (*sp)[curr];
}

ConstStrBlobPtr &ConstStrBlobPtr::incr() {
    check(curr, "increment past end of ConstStrBlobPtr");
    ++curr;
    return *this;
}

bool ConstStrBlobPtr::operator!=(const ConstStrBlobPtr &p) {
    return p.curr != curr;
}

int main() {
    StrBlob sb;
    ifstream ifs("../data/line.txt");

    if (ifs) {
        string word;
        while (ifs >> word) {
            sb.push_back(word);
        }
    }

    for (auto pbeg(sb.const_begin()), pend(sb.const_end()); pbeg != pend; pbeg.incr()) {
        std::cout << pbeg.deref() << std::endl;
    }

    return 0;
}