//
// Created by king on 2019/5/3.
//

#ifndef CPP_PRIMER_BINARYQUERY_HPP
#define CPP_PRIMER_BINARYQUERY_HPP


#include "Query_base.hpp"
#include "Query.hpp"


class BinaryQuery: public Query_base {

protected:
    BinaryQuery(const Query& l, const Query& r, std::string s):
    lhs(l), rhs(r), opSym(s) {

    }

    std::string rep() const {
        return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
    }

    Query lhs, rhs;
    std::string opSym;

};


#endif //CPP_PRIMER_BINARYQUERY_HPP
