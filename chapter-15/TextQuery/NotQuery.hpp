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

    }

    std::string rep() const {
        return "~(" + query.rep() + ")";
    }

    QueryResult eval(const TextQuery& tq) const;

    Query query;

};

inline Query operator~(const Query& q) {
    return std::shared_ptr<Query_base>(new NotQuery(q));
}


#endif //CPP_PRIMER_NOTQUERY_HPP
