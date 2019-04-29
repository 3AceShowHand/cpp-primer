//
// Created by king on 2019/4/29.
//

#ifndef CPP_PRIMER_PRINTSTRING_HPP
#define CPP_PRIMER_PRINTSTRING_HPP

#include <iostream>

class PrintString {

public:
    PrintString(std::ostream& o = std::cout , char c =' '):
    os(o), sep(c) {

    }

    void operator() (const std::string& s) const {
        os << s << sep;
    }

private:
    std::ostream& os;
    char sep;
};

#endif //CPP_PRIMER_PRINTSTRING_HPP
