//
// Created by king on 2019/5/3.
//

#include "OrQuery.hpp"

QueryResult OrQuery::eval(const TextQuery &tq) const {
    std::cout << "OrQuery::eval(const TextQuery &tq) const" << std::endl;

    auto left = lhs.eval(tq);
    auto right = rhs.eval(tq);

    auto ret_lines = std::make_shared<std::set<line_no_t>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());

    return QueryResult(rep(), ret_lines, left.get_file());
}