//
// Created by king on 2019/5/3.
//

#ifndef CPP_PRIMER_QUERY_HPP
#define CPP_PRIMER_QUERY_HPP

#include <string>
#include <iostream>

#include "QueryResult.hpp"
#include "TextQuery.hpp"
#include "Query_base.hpp"


class Query {
    friend Query operator~(const Query& q);
    friend Query operator|(const Query& rhs, const Query& lhs);
    friend Query operator&(const Query& rhs, const Query& lhs);

    friend std::ostream& operator<<(std::ostream& os, const Query& query);
public:
    Query(const std::string& s);

    QueryResult eval(const TextQuery& tq) const {
        return q->eval(tq);
    }

    std::string rep() const {
        return q->rep();
    }

private:
    Query(std::shared_ptr<Query_base> query): q(query) {

    }

    std::shared_ptr<Query_base> q;

};

Query operator~(const Query& q);
Query operator|(const Query& rhs, const Query& lhs);
Query operator&(const Query& rhs, const Query& lhs);

std::ostream& operator<<(std::ostream& os, const Query& query);

#endif //CPP_PRIMER_QUERY_HPP
