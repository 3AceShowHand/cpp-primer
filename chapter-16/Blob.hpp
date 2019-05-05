//
// Created by king on 2019/5/5.
//

#ifndef CPP_PRIMER_BLOB_HPP
#define CPP_PRIMER_BLOB_HPP

#include <memory>
#include <vector>

template <class T>
class Blob {
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

    void pop_back();

    value_type& back();

    value_type& operator[](size_type i);

private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string msg) const;
};


#endif //CPP_PRIMER_BLOB_HPP
