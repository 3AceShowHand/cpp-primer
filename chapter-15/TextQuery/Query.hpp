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
#include "WordQuery.hpp"


class Query {

    friend Query operator~(const Query& q);
    friend Query operator|(const Query& rhs, const Query& lhs);
    friend Query operator&(const Query& rhs, const Query& lhs);

    friend std::ostream& operator<<(std::ostream& os, const Query& query);

public:
    explicit Query(const std::string& s): q(new WordQuery(s)) {
        std::cout << "Query::Query(const std::string& s)" << std::endl;
    }

    QueryResult eval(const TextQuery& tq) const {
        std::cout << "Query::eval(const TextQuery& tq)" << std::endl;
        return q->eval(tq);
    }

    std::string rep() const {
        std::cout << "Query::rep()" << std::endl;
        return q->rep();
    }

private:
    Query(std::shared_ptr<Query_base> query): q(query) {
        std::cout << "Query::Query(std::shared_ptr<Query_base> query)" << std::endl;
    }

    std::shared_ptr<Query_base> q;

};

std::ostream& operator<<(std::ostream& os, const Query& query);



#endif //CPP_PRIMER_QUERY_HPP
