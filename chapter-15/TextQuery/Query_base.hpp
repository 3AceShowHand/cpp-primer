//
// Created by king on 2019/5/3.
//

#ifndef CPP_PRIMER_QUERY_BASE_HPP
#define CPP_PRIMER_QUERY_BASE_HPP

#include "TextQuery.hpp"

class Query_base {
    friend class Query;

protected:
    using line_no_t = TextQuery::line_no_t ;
    virtual ~Query_base() = default;

private:
    virtual QueryResult eval(const TextQuery& tq) const = 0;
    virtual std::string rep() const  = 0;
};

#endif //CPP_PRIMER_QUERY_BASE_HPP
