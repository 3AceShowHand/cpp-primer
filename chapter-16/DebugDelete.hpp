//
// Created by king on 2019/5/5.
//

#ifndef CPP_PRIMER_DEBUGDELETE_HPP
#define CPP_PRIMER_DEBUGDELETE_HPP

#include <iostream>


class DebugDelete {
public:
    DebugDelete(std::ostream& s = std::cerr): os(s) {

    }

    template <class T>
    void operator() (T* p) const {
        os << "deleting unique_ptr" << std::endl;
        delete p;
    }

private:
    std::ostream& os;
};


#endif //CPP_PRIMER_DEBUGDELETE_HPP
