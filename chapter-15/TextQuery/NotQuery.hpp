//
// Created by king on 2019/5/3.
//

#ifndef CPP_PRIMER_NOTQUERY_HPP
#define CPP_PRIMER_NOTQUERY_HPP


#include "Query_base.hpp"
#include "Query.hpp"


class NotQuery: public Query_base {
    friend Query operator~(const Query& q);

    NotQuery(const Query& q): query(q) {
        std::cout << "NotQuery::NotQuery(const Query& q)" << std::endl;
    }

    std::string rep() const {
        std::cout << "NotQuery::rep()" << std::endl;
        return "~(" + query.rep() + ")";
    }

    QueryResult eval(const TextQuery& tq) const;
    Query query;

};

inline Query operator~(const Query& q) {
    std::cout << "NotQuery::operator~(const Query& q)" << std::endl;
    return std::shared_ptr<Query_base>(new NotQuery(q));
}

#endif //CPP_PRIMER_NOTQUERY_HPP
