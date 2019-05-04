//
// Created by king on 2019/5/3.
//

#ifndef CPP_PRIMER_WORDQUERY_HPP
#define CPP_PRIMER_WORDQUERY_HPP


#include <iostream>
#include "Query_base.hpp"
#include "QueryResult.hpp"


class WordQuery: public Query_base {
    friend class Query;

    explicit WordQuery(const std::string& s): query_word(s) {
        std::cout << "WordQuery(const std::string& s)" << std::endl;
    }

    QueryResult eval(const TextQuery& t) const override {
        return t.query(query_word);
    }

    std::string rep() const override {
        return query_word;
    }

    std::string query_word;

};


#endif //CPP_PRIMER_WORDQUERY_HPP
