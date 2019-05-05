//
// Created by king on 2019/5/5.
//

#ifndef CPP_PRIMER_BLOB_HPP
#define CPP_PRIMER_BLOB_HPP

#include <memory>
#include <vector>
#include <iostream>


template <class> class BlobPtr;

template <class T>
class Blob {
    friend class BlobPtr<T>;

public:
    typedef T value_type;
    using size_type = typename std::vector<T>::size_type ;

    Blob();
    Blob(std::initializer_list<value_type> il);

    size_type size() const {
        return data->size();
    }

    bool empty() const {
        return data->empty();
    }

    void push_back(const value_type& t) {
        data->push_back(t);
    }

    void push_back(value_type&& t) {
        data->push_back(std::move(t));
    }

    BlobPtr<T> begin();
    BlobPtr<T> end();


    void pop_back();

    value_type& back();

    value_type& back() const;

    value_type& operator[](size_type i);
    value_type& operator[](size_type i) const;

private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string msg) const;
};

template<class T>
Blob<T>::Blob(): data(std::make_shared<std::vector<T>>()) {

}

template<class T>
Blob<T>::Blob(std::initializer_list<value_type> il):
        data(std::make_shared<std::vector<T>>(il)) {

}

template<class T>
void Blob<T>::pop_back() {
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template<class T>
typename Blob<T>::value_type& Blob<T>::back() {
    check(0, "back on empty Blob");
    return data->back();
}

template<class T>
typename Blob<T>::value_type& Blob<T>::operator[](Blob::size_type i) {
    check(i, "subscript out of range");
    return (*data)[i];
}

template<class T>
void Blob<T>::check(Blob::size_type i, const std::string msg) const {
    if (i >= size()) {
        throw std::out_of_range(msg);
    }
}

template<class T>
typename Blob<T>::value_type &Blob<T>::back() const {
    check(0, "back on empty Blob");
    return data->back();
}

template<class T>
typename Blob<T>::value_type &Blob<T>::operator[](Blob::size_type i) const {
    check(i, "subscript out of range");
    return (*data)[i];
}

template<class T>
BlobPtr<T> Blob<T>::begin() {
    return BlobPtr<T>(*this);
}

template<class T>
BlobPtr<T> Blob<T>::end() {
    return BlobPtr<T>(*this, size());
}

#endif //CPP_PRIMER_BLOB_HPP