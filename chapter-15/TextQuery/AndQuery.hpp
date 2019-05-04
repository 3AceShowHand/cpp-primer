//
// Created by king on 2019/5/3.
//

#ifndef CPP_PRIMER_ANDQUERY_HPP
#define CPP_PRIMER_ANDQUERY_HPP


#include "BinaryQuery.hpp"

class AndQuery: public BinaryQuery {
    friend Query operator&(const Query& lhs, const Query& rhs);

    AndQuery(const Query& left, const Query& right):
    BinaryQuery(left, right, "&") {

    }

    QueryResult eval(const TextQuery& tq) const override;
};

inline Query operator&(const Query& lhs, const Query& rhs) {
    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}


#endif //CPP_PRIMER_ANDQUERY_HPP
