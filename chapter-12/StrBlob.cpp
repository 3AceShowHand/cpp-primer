//
// Created by king on 2019/4/25.
//

#include "StrBlob.hpp"
#include "StrBlobPtr.hpp"
#include "ConstStrBlobPtr.hpp"

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {

}

StrBlob::StrBlob(std::initializer_list<std::string> il)
        : data(std::make_shared<std::vector<std::string>>(il)) {

}

void StrBlob::check(size_type pos, const std::string &msg) const {
    if (pos >= data->size())
        throw std::out_of_range(msg);
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

std::string &StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}

const std::string &StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string &StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

const std::string &StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data->size());
}

ConstStrBlobPtr StrBlob::const_begin() const {
    return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::const_end() const {
    return ConstStrBlobPtr(*this, data->size());
}

void StrBlob::push_back(const std::string &s) {
    data->push_back(s);
}

