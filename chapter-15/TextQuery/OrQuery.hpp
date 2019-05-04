//
// Created by king on 2019/5/3.
//

#ifndef CPP_PRIMER_ORQUERY_HPP
#define CPP_PRIMER_ORQUERY_HPP


#include "BinaryQuery.hpp"

class OrQuery : public BinaryQuery {
    friend Query operator|(const Query& lhs, const Query& rhs);
    OrQuery(const Query& lhs, const Query& rhs):
    BinaryQuery(lhs, rhs, "|") {
        std::cout << "OrQuery::OrQuery(const Query& lhs, const Query& rhs)" << std::endl;
    }

    QueryResult eval(const TextQuery& tq) const override;

};

inline Query operator|(const Query& lhs, const Query& rhs) {
    std::cout << "OrQuery::operator|(const Query& lhs, const Query& rhs)" << std::endl;
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}



#endif //CPP_PRIMER_ORQUERY_HPP
