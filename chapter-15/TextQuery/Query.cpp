//
// Created by king on 2019/5/3.
//

#include "Query.hpp"

Query operator~(const Query &q) {
    return Query(__cxx11::basic_string());
}

Query operator|(const Query &rhs, const Query &lhs) {
    return Query(__cxx11::basic_string());
}

Query operator&(const Query &rhs, const Query &lhs) {
    return Query(__cxx11::basic_string());
}

std::ostream &operator<<(std::ostream &os, const Query &query) {
    return os << query.rep();
}
