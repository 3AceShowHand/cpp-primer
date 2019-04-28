//
// Created by king on 2019/4/28.
//

#ifndef CPP_PRIMER_STRING_HPP
#define CPP_PRIMER_STRING_HPP

#include <memory>

class String {
public:

    String():String("") {}
    String(const char* cstr);

    String(const String& that);
    String& operator=(const String& that);

    String(String&& s) noexcept;
    String& operator=(String&& rhs) noexcept ;

    ~String();

    const char* c_str() {
        return elements;
    }

    size_t size() const {
        return first_free - elements;
    }

    size_t length() const {
        return size() - 1;
    }

    char* begin() const {
        return elements;
    }

    char* end() const {
        return first_free;
    }

private:
    char* elements;
    char* first_free;

    static std::allocator<char> alloc;

    std::pair<char*, char*> alloc_n_copy(const char* b, const char* e);
    void free();

};


#endif //CPP_PRIMER_STRING_HPP
