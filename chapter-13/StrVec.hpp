//
// Created by king on 2019/4/27.
//

#ifndef CPP_PRIMER_STRVEC_HPP
#define CPP_PRIMER_STRVEC_HPP

#include <memory>
#include <string>

class StrVec {

    friend bool operator==(const StrVec& lhs, const StrVec& rhs);
    friend bool operator!=(const StrVec& lhs, const StrVec& rhs);

    friend bool operator<(const StrVec& lhs, const StrVec& rhs);
    friend bool operator>(const StrVec& lhs, const StrVec& rhs);

    friend bool operator<=(const StrVec& lhs, const StrVec& rhs);
    friend bool operator>=(const StrVec& lhs, const StrVec& rhs);


public:

    StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {
    }

    StrVec(std::initializer_list<std::string> sl);

    StrVec(const StrVec&);

    StrVec& operator=(const StrVec&);

    StrVec(StrVec&& s);

    StrVec& operator=(StrVec&& rhs) noexcept;

    ~StrVec();

    void push_back(const std::string&);
    void push_back(std::string&& s);

    size_t size() const {
        return first_free - elements;
    }

    size_t capacity() const {
        return cap - elements;
    }

    std::string* begin() const {
        return elements;
    }

    std::string* end() const {
        return first_free;
    }

    void resize(int newSize);

    void resize(int newSize, const std::string& t );

    void reserve(int newCapacity);

    void shrink_to_fit();

private:

    std::string* elements;
    std::string* first_free;
    std::string* cap;

    static std::allocator<std::string> alloc;    // use for manage memory resource

    void free();
    std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
    void reallocate();

    void chk_n_alloc() {
        if (size() == capacity()) {
            reallocate();
        }
    }

    void range_initialize(const std::string* begin, const std::string* end);
};

bool operator==(const StrVec& lhs, const StrVec& rhs);
bool operator!=(const StrVec& lhs, const StrVec& rhs);

bool operator<(const StrVec& lhs, const StrVec& rhs);
bool operator>(const StrVec& lhs, const StrVec& rhs);

bool operator<=(const StrVec& lhs, const StrVec& rhs);
bool operator>=(const StrVec& lhs, const StrVec& rhs);


#endif //CPP_PRIMER_STRVEC_HPP
