//
// Created by king on 2019/5/5.
//

#ifndef CPP_PRIMER_BLOBPTR_HPP
#define CPP_PRIMER_BLOBPTR_HPP

#include <memory>
#include <vector>
#include "Blob.hpp"

template <class> class BlobPtr;

template <class T>
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);

template <class T>
bool operator!=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);

template <class T>
bool operator<(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);


template <class T>
class BlobPtr {

    friend bool operator==<T>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
    friend bool operator!=<T>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
    friend bool operator< <T>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);

public:
    BlobPtr(): wptr(), curr(0) {

    }

    explicit BlobPtr(Blob<T> &a, size_t sz=0):
    wptr(a.data), curr(sz) {

    }

    T& operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }

    // pre
    BlobPtr& operator++();
    BlobPtr& operator--();

    // post
    BlobPtr& operator++(int);
    BlobPtr& operator--(int);

private:
    std::shared_ptr<std::vector<T>> check(std::size_t i, const std::string& msg) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;

};

template<class T>
BlobPtr<T> &BlobPtr<T>::operator++(int) {
    BlobPtr ret = *this;
    ++*this;
    return ret;
}

template<class T>
BlobPtr<T> &BlobPtr<T>::operator--(int) {
    BlobPtr ret = *this;
    --*this;
    return ret;
}

template<class T>
BlobPtr<T> &BlobPtr<T>::operator++() {
    check(curr, "operator++ past the end of BlobPtr");
    ++curr;
    return *this;
}

template<class T>
BlobPtr<T> &BlobPtr<T>::operator--() {
    --curr;
    check(curr, "decrement past begin of BlobPtr");
    return *this;
}
template <class T>
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs) {
    if (lhs.wptr.lock() != rhs.wptr.lock()) {
        throw std::runtime_error("lhs and rhs point to different Blob");
    }
    return lhs.curr == rhs.curr;
}

template <class T>
bool operator!=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs) {
    return !(lhs == rhs);
}

template <class T>
bool operator<(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs) {
    if (lhs.wptr.lock() != rhs.wptr.lock()) {
        throw std::runtime_error("lhs and rhs point to different Blob");
    }
    return lhs.curr < rhs.curr;
}

template<class T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t i, const std::string &msg) const {
    std::shared_ptr<std::vector<T>> ret = wptr.lock();
    if (!ret) {
        throw std::runtime_error("unbound BlobPtr");
    } else if (i > ret->size()) {
        throw std::out_of_range(msg);
    }
    return ret;
}

#endif //CPP_PRIMER_BLOBPTR_HPP
